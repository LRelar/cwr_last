/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_09_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:22:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/11/28 14:49:09 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define OP_CODE 9
/*
TODO:	Сделать.
*/
void		op_zjmp(t_world *nexus, t_carry *carry, \
							t_dvasa *head, t_dvasa **vacant)
{
	t_mop	op_cont;

	(void)head;
	(void)vacant;
	ft_clone_op_cont(OP_CODE, &op_cont);
	if (carry->carry_flag)
	{
		ft_get_operands(&nexus->arena[sizeof(RTP)], &op_cont, carry, 1);
		carry->pos += (op_cont.operands[0] % op_cont.mod);
	}
	else
		carry->pos += op_cont.length;
	carry->op = 0;
	carry->exec_cyc++;
}