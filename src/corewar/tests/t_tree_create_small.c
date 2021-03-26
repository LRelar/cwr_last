/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tree_create_small.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:46:47 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/08 13:17:02 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define TCURRCYC	1350
#define TCURRDELTA	250
#define NUMOFCARS	2
/*
*	В данном тесте проверяется ft_leafnode_pick на случай, когда из текущей
	* лифноды перемещается ПОСЛЕДНЯЯ каретка, при этом, эта каретка становится
	* ПЕРВОЙ на исполнение в следующем цикле.
*/

inline static void	ft_form_tree(t_dvasa **tree, t_world *nexus)
{
	t_vasa			*ptr;

	if (!(*tree = ft_create_leafnode_r(NULL, 0)))
		return ;
	ptr = nexus->carry;
	while (ptr)
	{
		nexus->carry = nexus->carry->next;
		ft_add_offspring_by_id(*tree, ptr);
		ptr = nexus->carry;
	}
}

int						main(void)
{
	t_world				nexus;
	size_t				lifereg[NUMOFCARS] = { 1250, 1251 };
	size_t				cycle_arr[NUMOFCARS] = { 50, 1 };
	// size_t				iterator[5] = { 4, 4, 1, 4, 4 };
	int					k = 0;
	t_dvasa				*dvas_ptr = NULL;
	t_dvasa				*next = NULL;
	
	t_vasa				*vas_ptr = NULL;

	ft_bzero(&nexus, sizeof(nexus));
	nexus.cyc.cycle = TCURRCYC;
	nexus.cyc.cyc_to_die = TCURRDELTA;

	for (int i = 0; i < NUMOFCARS; i++)
	{
		ft_lstadd((t_list **)&nexus.carry, \
					(t_list *)ft_lstnew_r(ft_create_carry(), sizeof(t_carry)));
		nexus.carry->gen.carry->last_live_op = lifereg[i];
	}
	ft_form_tree(&dvas_ptr, &nexus);
	vas_ptr = dvas_ptr->gen.vasa;
	while (vas_ptr)
	{
		dvas_ptr->gen.vasa = dvas_ptr->gen.vasa->next;
		vas_ptr->gen.carry->exec_cyc = cycle_arr[k++];
		ft_leafnode_pick(vas_ptr, dvas_ptr, &next, &ft_add_offspring_by_id);
		vas_ptr = dvas_ptr->gen.vasa;
	}
	ft_leafnode_vacate(&dvas_ptr, &next);
	ft_tree_undertaker(&dvas_ptr, &next, &nexus.cyc);
	ft_destroy_leaftree(&dvas_ptr, &next);
	return (0);
}
