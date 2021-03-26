/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_gen_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:19:18 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:19:20 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void		ft_swap(void **a, void **b)
{
	void					*pocket;

	pocket = *a;
	*a = *b;
	*b = pocket;
}

inline static uint8_t	ft_bubblesorted(void **array, size_t size, \
															t_datacmp_rout *cmp)
{
	uint8_t				res;
	size_t				bogey;

	res = 1;
	bogey = 0;
	while (bogey < size - 1)
	{
		if (cmp(array[bogey], array[bogey + 1]))
		{
			res = 0;
			ft_swap(&array[bogey], &array[bogey + 1]);
		}
		bogey++;
	}
	return (res);
}

void					ft_srt_bubble_genarr(void **array, size_t size, \
															t_datacmp_rout *cmp)
{
	size_t				bogey;

	bogey = 0;
	while (bogey < size)
	{
		if (ft_bubblesorted(array, size - bogey, cmp))
			return ;
		bogey++;
	}
}
