/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_atoi_iterator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 08:21:50 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/15 08:32:01 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

inline static int		ft_numvol(long long int n)
{
	size_t				v;

	v = 0 + (n <= 0);
	
	while (n && ++v)
		n /= 10;
	return (v);
}


int			main(void)
{
	long long k = 0;
	long long v = 0;

	v = ft_numvol(k);

	k = INT64_MAX;
	v = ft_numvol(k);

	k = INT64_MIN;
	v = ft_numvol(k);

	return (0);
}