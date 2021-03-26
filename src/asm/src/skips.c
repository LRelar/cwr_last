/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skips.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 23:57:03 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/19 00:34:00 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		skip_first_part(char **word)
{
	if (**word == DIRECT_CHAR)
		(*word)++;
	if (**word == '-' || **word == '+')
		(*word)++;
	while (ft_isdigit(**word) && **word)
		(*word)++;
}

char		skip_num(char **wrd, long long num)
{
	long long	pow;
	long long	tmp;

	while (ft_charinstr(" \t+-\v", **wrd))
		(*wrd)++;
	pow = 10;
	if (**wrd == '0' && *(*wrd + 1))
		pow = *(*wrd + 1) == 'x' || *(*wrd + 1) == 'X' ? 16 : 8;
	if (**wrd == '0' && pow == 10 && !num)
		return (*(++(*wrd)));
	*wrd += (pow % 8 == 0) + (pow == 16);
	while (num)
	{
		tmp = 1;
		while (num / tmp != (**wrd - '0') && tmp < num)
			tmp *= pow;
		if (num / tmp == (**wrd - '0'))
		{
			num -= tmp * (**wrd - '0');
			(*wrd)++;
		}
		else
			return (-1);
	}
	return (num == 0 && (ft_charinstr(" \t+-\v", **wrd) || !**wrd) ? 0 : -1);
}

void		skip_space(char **str)
{
	int	i;

	i = 0;
	while (**str == ' ' || **str == '\t')
	{
		(*str)++;
		i++;
	}
	g_column += i;
}

void		ast_strrtrim(char *word)
{
	char *cpy;

	if (!*word)
		return ;
	cpy = word;
	while (*word)
		word++;
	word--;
	while (cpy != word && ft_isspace(*word))
		*word-- = '\0';
}
