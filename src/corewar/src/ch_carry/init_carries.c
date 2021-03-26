/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:57:16 by mschimme          #+#    #+#             */
/*   Updated: 2021/02/26 23:11:07 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	'current == previous' means ft_lstadd haven't iterated the given
**	alst (&nexus->carry) due to ft_lstnew_r failure.
**	'!(current->gen.carry)' means ft_create_carry() failed but ft_lstnew_r
**	succeeded.
!	Leaks if ft_create_carry() succeeded but ft_lstnew_r failed.
*/
inline static uint8_t	ft_check_production(t_vasa *current, t_vasa *previous)
{
	if (current == previous || \
		!(current->gen.carry))
		return (1);
	return (0);
}

/*
TODO: Проверить в боевом режиме.
*/
inline static void		ft_init_carry_origin(t_carry *carry, t_champ *parent, \
															uintptr_t position)
{
	carry->reg[0] = -(parent->id);
	carry->parent = parent;
	carry->pos = position;
	carry->exec_cyc = 0;
}

void					ft_init_carries(t_world *nexus)
{
	uintptr_t	entry_ptr;
	uintptr_t	step;
	t_vasa		*canary;
	t_champ		**ch_ptr;

	step = MEM_SIZE / (nexus->champs);
	ch_ptr = nexus->champ_ord;
	entry_ptr = 0;
	while (*ch_ptr)
	{
		canary = nexus->carry;
		ft_lstadd((t_list **)&(nexus->carry), \
					ft_lstnew_r(ft_create_carry(), sizeof(t_carry)));
		if (ft_check_production(nexus->carry, canary))
				ft_prox_err_malloc("new carry or its container", __func__);
		ft_init_carry_origin(nexus->carry->gen.carry, *ch_ptr, entry_ptr);
		entry_ptr += step;
		ch_ptr++;
	}
}