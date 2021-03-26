/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lobby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:31:22 by mschimme          #+#    #+#             */
/*   Updated: 2021/02/22 21:35:43 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
TD:	Проверить в боевом режиме.
// TD:	ПЕРЕДЕЛАТЬ. Используется ft_add_offspring_by_order
*/
inline static void	ft_form_tree(t_dvasa **tree, t_world *nexus)
{
	t_vasa			*ptr;

	if (!(*tree = ft_create_leafnode_r(NULL, 0)))
		return ;
	while (nexus->carry)
	{
		ptr = nexus->carry->next;
		ft_add_offspring_by_id(*tree, nexus->carry);
		nexus->carry = ptr;
	}
}

void					ft_exec_battle(t_world *nexus)
{
	t_dvasa				*tree;

	tree = NULL;
	ft_form_tree(&tree, nexus);
	if (!tree)
		ft_manage_world(NULL);
	if (nexus->flags & 1)
		ft_the_dump_cycle(nexus, tree);
	else
		ft_the_cycle(nexus, tree);
}
