/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_05_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:22:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/11/04 11:20:53 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define OP_CODE 5

/*
**!Контракт:
**	*	Параметры, такие же как у всех остальных op-функций.
**	*	По результатам работы должна модифицировать carry->exec_cyc, в 
**		* соответствии с прочитанным и валидированным op-code.
**	*	Должна модифицировать carry->op соответствующим корректным прочитанным
**		* с арены op-code.
**	*	Должна проитерировать указатель carry на арену, если прочитан кривой
**		* op-code.
**	Function evaluates op-code read from arena (with VALID_OP_CODE macro) 
**	resulting carry->op == either op-code written in arena or == 0.
**	Op-code evaluated == 0 means nothing to do with current carry->pos(ition)
**	We iterate position on this occasion (by 1).
**	As finale we prepare to place our carry in queue of the next cycle.
**	Tester:		t_op_05_sub.c
*/

void		op_sub(t_world *nexus, t_carry *carry, \
							t_dvasa *head, t_dvasa **vacant)
{
	t_mop	op_cont;

	(void)head;
	(void)vacant;
	ft_clone_op_cont(OP_CODE, &op_cont);
	if (!(ft_eval_operands_type(&nexus->arena[sizeof(RTP)], carry->pos, \
									&op_cont, ft_get_op_cont(OP_CODE))))
	{
		ft_get_operands(&nexus->arena[sizeof(RTP)], &op_cont, carry, \
													op_cont.ops_amount - 1);
		carry->reg[op_cont.operands[2]] = op_cont.operands[0] - \
											op_cont.operands[1];
		carry->carry_flag = (t_bool)(!carry->reg[op_cont.operands[2]]);
	}
	carry->op = 0;
	carry->pos += op_cont.length;
	carry->exec_cyc++;
}
