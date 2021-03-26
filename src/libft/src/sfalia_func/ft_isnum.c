/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:59:37 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:44:16 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumber(char *str)
{
	char	*cpy;
	int		f;

	if (!str || !*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	f = 0;
	if (!ft_strncmp("0x", str, 2) || !ft_strncmp("0X", str, 2))
	{
		str += 2;
		f = 1;
	}
	cpy = str;
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9')
			|| (f && ft_toupper(*str) >= 'A' && ft_toupper(*str) <= 'F')))
			return (0);
		str++;
	}
	return (str != cpy);
}

long long	ft_maxint(unsigned char bytes, int unsig)
{
	long long	rez;

	unsig = !unsig;
	rez = 0;
	while (bytes--)
		rez |= 0xffL << ((bytes * 8) - (unsig ? unsig-- : 0));
	return (rez);
}
