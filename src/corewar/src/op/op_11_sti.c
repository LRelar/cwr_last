/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_11_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:22:49 by mschimme          #+#    #+#             */
/*   Updated: 2021/02/22 19:43:09 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define OP_CODE 11

/*
TODO:	Сделать.
*/
void			op_sti(t_world *nexus, t_carry *carry, \
							t_dvasa *head, t_dvasa **vacant)
{
	t_mop		op_cont;

	(void)head;
	(void)vacant;
	ft_clone_op_cont(OP_CODE, &op_cont);
	if (!(ft_eval_operands_type(&nexus->arena[sizeof(RTP)], carry->pos, \
											&op_cont, ft_get_op_cont(OP_CODE))))
	{
		ft_get_operands(&nexus->arena[sizeof(RTP)], &op_cont, carry, \
													op_cont.ops_amount);
		ft_set_bytecode(&nexus->arena[sizeof(RTP)], \
		carry->pos + (op_cont.operands[1] + op_cont.operands[2]) % op_cont.mod,
		op_cont.operands[0], DIR_SIZE);
	}
	carry->op = 0;
	carry->pos += op_cont.length;
	carry->exec_cyc++;
}