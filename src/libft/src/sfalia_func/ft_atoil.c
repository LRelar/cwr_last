/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 01:30:37 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:47:58 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_atoil(const char *str)
{
	long long	res;
	int			sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str += 1;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
	{
		str += 1;
	}
	res = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str += 1;
		if (res < 0)
			return (sign == -1 ? 0 : -1);
	}
	res *= sign;
	return (res);
}
