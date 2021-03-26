/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:55:21 by mschimme          #+#    #+#             */
/*   Updated: 2021/02/22 18:48:33 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <cwr_man.h>

#define _WRONG_SEPARATOR(x, y) (*(_SEP_TYPE *)(x + y) != 0)
#define CH_NAME curr->name

inline static void		ft_get_magicname(int fd, t_vasa **error, t_champ *curr)
{
	ssize_t			res;
	RTP				magic;

	magic = 0;
	if ((res = read(fd, (void *)&magic, REG_SIZE)) != REG_SIZE)
	{
		ft_err_invalid_filesize(error, "Magic number field");
		return ;
	}
	if (magic != (int)(ft_swap_endian(COREWAR_EXEC_MAGIC, 4)))
		ft_err_invalid_cwr_magic(error, NULL);
	if ((res = read(fd, curr->name, (PROG_NAME_LENGTH + REG_SIZE))) != \
												PROG_NAME_LENGTH + REG_SIZE)
	{
		ft_err_invalid_filesize(error, "Champion name field");
		return ;
	}
	if (ft_ctrl_detect((void *)curr->name, PROG_NAME_LENGTH))
		if (ft_ask_user(WAR_CTRL_1))
			ft_err_invalid_name(error, NULL);
	if (_WRONG_SEPARATOR(curr->name, PROG_NAME_LENGTH))
		ft_err_invalid_separator(error, "between Name and Comment.");
}

inline static void		ft_get_champ_size(int fd, \
										t_vasa **champ_error, t_champ *champ)
{
	ssize_t			res;
	RTP				size;

	if ((res = read(fd, (void *)&size, REG_SIZE)) != REG_SIZE)
	{
		ft_err_invalid_filesize(champ_error, "File size field.");
		return ;
	}
	champ->size = (RTP)(ft_swap_endian(size, 4));
	if (champ->size > CHAMP_MAX_SIZE)
		ft_err_invalid_champsize(champ_error, NULL);
}

inline static void		ft_get_champ_comment(int fd, \
										t_vasa **champ_error, t_champ *champ)
{
	ssize_t			res;

	if ((res = read(fd, champ->desc, COMMENT_LENGTH + REG_SIZE)) != \
													COMMENT_LENGTH + REG_SIZE)
	{
		ft_err_invalid_filesize(champ_error, "Champion Comment field");
		return ;
	}
	// if (ft_ctrl_detect((void *)champ->desc, COMMENT_LENGTH))
	// 	if (ft_ask_user(WAR_CTRL_2))
	// 		ft_err_invalid_comment(champ_error, NULL);
	if (_WRONG_SEPARATOR(champ->desc, COMMENT_LENGTH))
		ft_err_invalid_separator(champ_error, "between Comment and Body.");
}

inline static void		ft_get_champ_body(int fd, \
										t_vasa **champ_error, t_champ *champ)
{
	ssize_t			res;
	int				buff;

	buff = 0;
	if (!(champ->body = (uint8_t *)ft_memalloc((size_t)(champ->size))))
	{
		ft_err_malloc("champ->body", __func__);
		ft_lstdel((t_list **)champ_error, &ft_del);
		ft_manage_world(NULL);
		return ;
	}
	if ((res = read(fd, (void *)(champ->body),
						(size_t)champ->size)) != (ssize_t)champ->size)
	{
		ft_err_invalid_filesize(champ_error, "Champion body field");
		return ;
	}
	if (read(fd, &buff, 1))
		ft_err_invalid_bodysize(champ_error, NULL);
}

/*
**	int *offset из корня функций можно использовать для подсчета успешно загру-
**	женных чемпионов. Тогда эта функция должна возвращать int 1, если мы
**	успешно прочитали чемпиона и int 0, если облажалилсь. *offset +=
**	ft_read_champ_file как итератор на выходе из этой функции.
*/

int						ft_read_champ_file(char *file, int id, t_champ *champ, \
															t_vasa **last_error)
{
	static int	pos;
	t_vasa		*ch_errors;
	int			fd;

	if (pos == MAX_PLAYERS)
		return
		(ft_prox_err_ret(last_error, (void *)file, &ft_err_champ_limit));
	if ((fd = open(file, O_RDONLY)) == -1)
		return
		(ft_prox_err_ret(last_error, (void *)file, &ft_err_invalid_filename));
	ch_errors = NULL;
	ft_get_magicname(fd, &ch_errors, &champ[pos]);
	ft_get_champ_size(fd, &ch_errors, &champ[pos]);
	ft_get_champ_comment(fd, &ch_errors, &champ[pos]);
	ft_get_champ_body(fd, &ch_errors, &champ[pos]);
	champ[pos].id = id;
	if (ch_errors)
		return (ft_ch_err_manager(file, &ch_errors, last_error, &champ[pos]));
	pos++;
	close(fd);
	return (1);
}
