/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_cpy_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:28:58 by andru196          #+#    #+#             */
/*   Updated: 2020/08/20 00:30:07 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_otab[OP_TAB_SIZE];

int			word_iscomand(char *word, int len)
{
	int i;

	i = -1;
	if (len)
		while (++i < OP_TAB_SIZE - 1)
			if (!ft_strncmp(g_otab[i].name, word, ft_strlen(g_otab[i].name)))
				return (1);
	return (0);
}

int			cpy_word(char *dst, char *src)
{
	int len;

	len = 0;
	while (len < MAX_WORD_LEN && *src != ' ' && *src != '\t'
		&& *src != COMMENT_CHAR && *src != ALT_COMMENT_CHAR
		&& *src != SEPARATOR_CHAR && *src && *src != QUOTE_CHAR
		&& !((*src == DIRECT_CHAR || *src == '+' || *src == '-')
		&& word_iscomand(dst - len, len)))
	{
		len++;
		*dst++ = *src++;
	}
	if (*src == SEPARATOR_CHAR)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}

int			cpy_arg_word(char *dst, char *src)
{
	int len;

	len = 0;
	while (len < MAX_WORD_LEN && *src != COMMENT_CHAR
	&& *src != ALT_COMMENT_CHAR && *src != SEPARATOR_CHAR && *src)
	{
		len++;
		*dst++ = *src++;
	}
	if (*src == SEPARATOR_CHAR)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}

void		prepare_arg(char *word, long long *arg)
{
	long long	rez;
	long long	tmp;
	char		*cpy;

	skip_first_part(&word);
	while (*word && *word != '+' && *word != '-')
		word++;
	if (!*word)
		return ;
	cpy = word;
	while (ft_isspace(*(cpy - 1)))
		cpy--;
	rez = 0;
	while (*word)
	{
		if (*word == '+' && (g_flag & fl_sum))
			tmp = ft_atoix(word + 1);
		if (*word == '-')
			tmp = ft_atoix(word + 1);
		if (skip_num(&word, tmp) == -1)
			return ;
		rez += tmp;
	}
	*arg = rez;
	*cpy = '\0';
}
