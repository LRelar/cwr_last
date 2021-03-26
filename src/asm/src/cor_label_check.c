/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_label_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:17:18 by andru196          #+#    #+#             */
/*   Updated: 2020/08/20 00:29:58 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			check_chars(char *word)
{
	while (*word)
		if (!ft_charinstr(LABEL_CHARS, *word++))
			return (0);
	return (1);
}

static char			find_label(t_asmcont *c, char *word)
{
	t_label	*tmp;

	tmp = c->label_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, word))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	tmp->dst = &c->command_list[c->cmd_count];
	tmp->row = g_row;
	return (1);
}

int					label_check(t_asmcont *c, char *word, int len)
{
	if (len > MAX_WORD_LEN)
		return (LABEL_SIZE_ERROR);
	*(word + --len) = '\0';
	if (!check_chars(word))
		return (LABEL_FORBIDDEN_CHAR);
	if (!find_label(c, word))
		if (!new_label(c, word))
			return (MALLOC_ERROR);
	return (1);
}

/*
** Проверяет, что лейб состоит из нужных символов и не вылазит за границы масси
*/

int					arg_label_check(char *wrd)
{
	int i;

	i = 0;
	while (*wrd && *wrd != SEPARATOR_CHAR)
	{
		if (!ft_charinstr(LABEL_CHARS, *wrd++))
			return (0);
		i++;
	}
	return (i && i <= MAX_WORD_LEN);
}

t_cmnd_label_link	*add_label_arg(t_asmcont *c, char *wrd, int arg_n)
{
	int					i;
	char				wrd_cpy[MAX_WORD_LEN + 1];
	t_cmnd_label_link	*rez;

	ft_bzero(wrd_cpy, MAX_WORD_LEN + 1);
	i = 0;
	while (*wrd && *wrd != SEPARATOR_CHAR)
		wrd_cpy[i++] = *wrd++;
	rez = c->conn_list;
	if (!rez)
		return (c->conn_list = new_connect(c, arg_n, wrd_cpy));
	else
		while (rez->next)
			rez = rez->next;
	return (rez->next = new_connect(c, arg_n, wrd_cpy));
}
