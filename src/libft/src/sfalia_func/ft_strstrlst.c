/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:47:16 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:41:30 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrlst(const char *haystack, const char *needle)
{
	char		*cpy;
	int			len_h;
	int			len_n;

	if (*needle == '\0')
		return ((char*)haystack);
	if (!haystack || !needle || !*haystack)
		return (NULL);
	len_h = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	if (len_h < len_n)
		return (NULL);
	cpy = (char *)haystack + len_h - len_n;
	while (cpy != haystack)
		if (!ft_strncmp(needle, (const char *)cpy--, len_n))
			return (++cpy);
	return (NULL);
}
