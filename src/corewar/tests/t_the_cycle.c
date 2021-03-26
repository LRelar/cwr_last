/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_the_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:13:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/11 18:46:07 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

inline static void		ft_cycle_control(t_world *nexus, \
											t_dvasa **tree, t_dvasa **vacant)
{
	t_cycle				*cyc_ptr;

	cyc_ptr = &nexus->cyc;
	if (cyc_ptr->cycle == cyc_ptr->next_check)
	{
		ft_tree_undertaker(tree, vacant, cyc_ptr);
		if (++cyc_ptr->num_of_checks == MAX_CHECKS || \
											cyc_ptr->lives_done >= NBR_LIVE)
		{
			cyc_ptr->cyc_to_die = (cyc_ptr->cyc_to_die - CYCLE_DELTA) * \
										(cyc_ptr->cyc_to_die >= CYCLE_DELTA);
			cyc_ptr->num_of_checks = 0;
		}
		cyc_ptr->next_check += cyc_ptr->cyc_to_die + (cyc_ptr->cyc_to_die == 0);
		cyc_ptr->lives_done = 0;
	}
}

/*
**	Returns either 0, or a value
*/

inline static uint8_t	ft_eval_op_code_valid(uint8_t op_code)
{
	return ((op_code >= 0 && op_code < KNOWN_OPS) * op_code);
}

inline static void		ft_carry_process(t_world *nexus, t_dvasa **tree, \
															t_dvasa **new_node)
{
	static t_op_rout	*op_tab[KNOWN_OPS] = { &op_new_op, &op_live, &op_ld,
											&op_st, &op_add, &op_sub, &op_and,
											&op_or, &op_xor, &op_zjmp, &op_ldi,
											&op_sti, &op_fork, &op_lld,
											&op_lldi, &op_lfork, &op_aff };
	uint8_t				op_code;
	t_vasa				*carry_bogey;

	carry_bogey = (*tree)->gen.vasa;
	if (nexus->cyc.cycle == carry_bogey->gen.carry->exec_cyc)
	{
		while (carry_bogey)
		{
			carry_bogey->gen.carry->pos = \
									ft_calc_addr(carry_bogey->gen.carry->pos);
			(*tree)->gen.vasa = (*tree)->gen.vasa->next;
			op_code = ft_eval_op_code_valid(nexus->arena[sizeof(RTP) + \
												carry_bogey->gen.carry->pos]);
			op_tab[op_code * (carry_bogey->gen.carry->op != 0)](nexus, \
									carry_bogey->gen.carry, *tree, new_node);
			ft_leafnode_pick(carry_bogey, *tree, new_node, &ft_carry_ins_by_id);
			carry_bogey = (*tree)->gen.vasa;
		}
		ft_leafnode_vacate(tree, new_node);
	}
}

void					ft_the_cycle(t_world *nexus, t_dvasa *tree)
{
	t_dvasa				*vacant;
	uint8_t				dump_fl;
	t_vasa				*curr_carry;

	curr_carry = NULL;
	vacant = NULL;
	dump_fl = nexus->flags;
	while (tree)
	{
		nexus->cyc.cycle++;
		ft_carry_process(nexus, &tree, &vacant);
		ft_cycle_control(nexus, &tree, &vacant);
		if (dump_fl && nexus->cyc.cycle == nexus->cyc.cyc_to_dump->gen.cyc_sol)
			if (ft_print_dump(&nexus->cyc.cyc_to_dump))
				break ;
	}
}
