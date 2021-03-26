/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:23:10 by mschimme          #+#    #+#             */
/*   Updated: 2020/12/08 00:17:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <cwr_man.h>

/*
**	More about tcflush @
*/

inline static int	ft_get_term_width(void)
{
	struct winsize	ws_out;
	int				res;

	ft_bzero(&ws_out, sizeof(struct winsize));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws_out);
	res = (int)ws_out.ws_col;
	if (!res)
		res = 80;
	return (res);
}

static void			ft_print_intro(void)
{
	int		width;

	width = ft_get_term_width();
	ft_printf_fd(2, "=>{red}%*s{eoc}\n", \
			ALIGN_MID(ft_strlen(WRN_HDR)), WRN_HDR);
	ft_printf_fd(2, "=>{red}%*s{eoc}\n", \
			ALIGN_MID(ft_strlen(WRN_BDY)), WRN_BDY);
	ft_show_man();
	ft_printf_fd(2, \
			"%s\n%s%s", ERR_DESC_1, ERR_DESC_2, ERR_DESC_3);
}

static void			ft_print_errors(t_vasa *ptr)
{
	t_error	*err;

	while (ptr)
	{
		err = ptr->gen.error;
		if (err)
		{
			ft_printf_fd(2, "{yellow}WARNING:{eoc}\t%s\n", err->errmessage);
			if (*(err->errmessage) != '=')
				ft_printf_fd(2, "{green}OBJECT:{eoc}\t\t%s\n", err->argv_tar);
		}
		ptr = ptr->next;
	}
}

static uint8_t		ft_get_action(void)
{
	char		buff[5];

	ft_printf_fd(1, "%s\n%s\n", ERR_STAT_1, ERR_INPUT);
	while (read(STDIN_FILENO, (void *)&buff[0], 4))
	{
		if (*(int *)&buff[0] == 0x0a1b || !ft_strcasecmp(&buff[0], "no\n"))
		{
			tcflush(STDIN_FILENO, TCIFLUSH);
			return (1);
		}
		else if (*(int *)&buff[0] == '\n' || !ft_strcasecmp(&buff[0], "yes\n"))
		{
			tcflush(STDIN_FILENO, TCIFLUSH);
			return (0);
		}
		else
		{
			tcflush(STDIN_FILENO, TCIFLUSH);
			ft_bzero(buff, sizeof(buff));
			ft_printf_fd(1, "%s %s\n", ERR_STAT_2, ERR_INPUT);
		}
	}
	return (1);
}

uint8_t				ft_supervise_input(t_world *nexus, int ch_amount)
{
	uint8_t	flag;

	flag = 0;
	if (!ch_amount)
	{
		ft_err_nochamps(&nexus->errors, NULL);
		flag = 1;
	}
	ft_check_id(&nexus->errors, &nexus->champ[0], ch_amount);
	if (nexus->errors)
	{
		ft_print_intro();
		ft_print_errors(nexus->errors);
		nexus->flags = (NULL != nexus->cyc.cyc_to_dump);
		if (!flag)
			return (ft_get_action());
	}
	return (flag);
}
