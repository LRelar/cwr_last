/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:58:59 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/19 00:34:29 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		cor_scan_word(t_asmcont *cont, char **str, int fd)
{
	char	word[MAX_WORD_LEN + 1];
	int		len;
	int		rez;

	skip_space(str);
	len = cpy_word(word, *str);
	*str += len;
	rez = 0;
	if ((!cont->champ_name && !ft_strcmp(word, NAME_CMD_STRING))
	|| (!cont->comment && !ft_strcmp(word, COMMENT_CMD_STRING)))
	{
		g_column += len;
		rez = special_arg(cont, ft_strcmp(word, NAME_CMD_STRING), str, fd);
	}
	else if (!cont->champ_name || !cont->comment)
		return (cont->champ_name ? NONE_COMMENT_ERROR : NONE_PROG_NAME_ERROR);
	else if (*(*str - 1) == LABEL_CHAR)
		if ((rez = label_check(cont, word, len)) > 0)
			g_column += len;
	if (!rez)
		rez = command_check(cont, word, str, len);
	if (!rez)
		rez = -1;
	return (rez);
}

static int		cor_scan(t_asmcont *cont, char *str, int fd)
{
	int		rez;
	char	*move;

	rez = 0;
	while (*str && rez >= 0)
	{
		move = str;
		skip_space(&str);
		if (!*str || *str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR)
			break ;
		rez = cor_scan_word(cont, &str, fd);
		if (!str || !*str || rez < 0)
			break ;
		if (move == str)
			str++;
	}
	return (rez);
}

static int		cor_read(int fd, t_asmcont *cont)
{
	int		rez;
	char	*buf;

	g_row = 0;
	while ((rez = get_next_line(fd, &buf)) > 0)
	{
		g_row++;
		g_column = 0;
		if ((size_t)g_gnl_read > ft_strlen(buf))
		{
			while (*(buf + g_column) && ft_isascii(*(buf + g_column)))
				g_column++;
			ft_strdel(&buf);
			rez = BAD_SYMBOL_ERROR;
			break ;
		}
		rez = cor_scan(cont, buf, fd);
		ft_strdel(&buf);
		if (rez < 0)
			break ;
	}
	while (rez < 0 && get_next_line(fd, &buf))
		ft_strdel(&buf);
	return (rez);
}

void			free_asm_data(t_asmcont *c)
{
	void *tmp;
	void *pre;

	ft_memdel((void **)&c->champ_name);
	ft_memdel((void **)&c->comment);
	ft_memdel((void **)&c->command_list);
	tmp = c->conn_list;
	pre = tmp;
	while (tmp)
	{
		tmp = ((t_cmnd_label_link *)tmp)->next;
		free(pre);
		pre = tmp;
	}
	c->conn_list = NULL;
	tmp = c->label_list;
	pre = tmp;
	while (tmp)
	{
		tmp = ((t_label *)tmp)->next;
		free(pre);
		pre = tmp;
	}
	c->label_list = NULL;
}

int				cor_open_file(char *file_name, int flag)
{
	int			fd;
	int			code;
	t_asmcont	cont;

	code = 0;
	g_column = 0;
	g_row = 0;
	if (ft_strendwith(file_name, SOURCE_EXTENSION)
		|| ft_strendwith(file_name, SOURCE_UPEXTENSION))
	{
		if ((fd = open(file_name, O_RDONLY)) != -1)
		{
			init_container(&cont);
			code = cor_read(fd, &cont);
			close(fd);
			if (code >= 0)
				code = asm_translate(&cont, file_name, flag);
			free_asm_data(&cont);
		}
		else
			code = OPEN_FILE_ERROR;
	}
	else
		code = SOURCE_EXTENSION_ERROR;
	return (code);
}
