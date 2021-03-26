/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_head_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:10:41 by mschimme          #+#    #+#             */
/*   Updated: 2020/11/15 18:17:19 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

RTP			ft_get_nil_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	(void)arena;
	(void)op_cont;
	(void)carry;
	(void)pos;
	ft_printf("\n!!! We entered ft_get_nil_val somehow!!!'\n");
	return (0);
}

void			ft_set_nil_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	(void)arena;
	(void)op_cont;
	(void)carry;
	(void)pos;
	ft_printf("\n!!! We entered ft_set_nil_val somehow!!!'\n");
}

void			ft_set_reg_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	(void)arena;
	(void)pos;
	carry->reg[op_cont->operands[1]] = op_cont->operands[0];
}

void			ft_set_dir_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	(void)arena;
	(void)op_cont;
	(void)carry;
	(void)pos;
	ft_printf("\n!!! We entered ft_set_dir_val somehow!!!'\n");
}

void			ft_set_ind_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	intptr_t	offset;

	(void)pos;
	offset = (intptr_t)(carry->pos + op_cont->operands[1]);
	ft_set_bytecode(arena, offset, op_cont->operands[0], DIR_SIZE);
}
