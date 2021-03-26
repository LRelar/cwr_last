/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 14:51:30 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/08 14:06:53 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
*	ПРОВЕРИЛ.
*/
inline static t_champ	**ft_build_champ_chain(t_champ *champ_arr, int champs)
{
	t_champ				**res;
	int					i;

	res = NULL;
	if (!(res = (t_champ **)ft_memalloc((champs + 1) * sizeof(t_champ **))))
		return (NULL);
	i = 0;
	while (i < champs)
	{
		res[i] = &champ_arr[i];
		i++;
	}
return (res);
}

/*
*	ПРОВЕРИЛ.
*/
int						ft_champ_ptr_leftid_grt_rightid(void *left, void *right)
{
	return (((t_champ *)left)->id > ((t_champ *)right)->id);
}

t_champ					**ft_build_champarr_sorted(t_champ *champ_arr,\
																	int champs)
{
	t_champ				**chain;

	if (!(chain = ft_build_champ_chain(champ_arr, champs)))
		ft_manage_world(NULL);
	ft_srt_bubble_genarr((void **)chain, (size_t)champs, \
											&ft_champ_ptr_leftid_grt_rightid);
	return (chain);
}