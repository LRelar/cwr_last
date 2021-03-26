/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 23:22:34 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:29:32 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char			*ft_strjoinnl(char *s1, char *s2)
{
	char	*rez;
	char	*cpy;

	cpy = ft_strjoin(s1, "\n");
	rez = ft_strjoin(cpy, s2);
	free(cpy);
	return (rez);
}

static int			multy_line_arg(int fd, char **rez, size_t *size)
{
	char	*buf;
	char	*cpy;
	char	*rezcpy;
	int		gnl;
	int		frst;

	frst = 0;
	while ((gnl = get_next_line(fd, &buf)) > 0 && ++g_row)
	{
		rezcpy = *rez;
		if ((cpy = ft_strchr(buf, QUOTE_CHAR)))
			*cpy = '\0';
		if (!(*rez = ft_strjoinnl(*rez, buf)))
			return (1);
		if (frst || frst++)
			free(rezcpy);
		free(buf);
		if (cpy)
		{
			*size = ft_strlen(*rez) - 1;
			return (0);
		}
	}
	ft_strdel(rez);
	return (1);
}

int					special_arg(t_asmcont *c, int dst, char **str, int fd)
{
	char	*cpy[2];
	size_t	size[2];

	size[0] = 0;
	while ((*str)[size[0]] == ' ' || (*str)[size[0]] == '\t')
		size[0]++;
	*str += size[0];
	g_column += size[0];
	if (**str != '"' || (!(cpy[0] = ft_strchr(*str + 1, QUOTE_CHAR))
		&& multy_line_arg(fd, str, &(size[1]))))
		return (NONE_QUOTE_ERROR);
	else if (**str == '"' && cpy[0])
		size[1] = cpy[0] - *str - 1;
	if (!(cpy[1] = ft_strnew(size[1])))
		return (MALLOC_ERROR);
	ft_memcpy(cpy[1], *str + 1, size[1]);
	g_column = size[1] + (ft_strstr(*str, "\n") ?
		-(ft_strstrlst(*str, "\n") - *str + 1) : g_column + 2);
	if (ft_strchr(*str, '\n'))
		ft_strdel(str);
	else
		*str += size[1] + 1 + !ft_strstr(*str, "\n");
	if (dst)
		return (ft_strlen(c->comment = cpy[1]) > COMMENT_LENGTH ? LCERR : 2);
	return (ft_strlen(c->champ_name = cpy[1]) > PROG_NAME_LENGTH ? LNERR : 2);
}
