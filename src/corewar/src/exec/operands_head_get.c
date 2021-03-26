/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_head_get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:05:39 by mschimme          #+#    #+#             */
/*   Updated: 2020/11/15 17:45:06 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	This function get the index of the regiester undergoing a change.
*/

RTP		ft_get_reg_num(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	(void)op_cont;
	(void)carry;
	return ((RTP)(arena[ft_calc_addr(pos)] - 1));
}

/*
**	This function get the value of the offset that is written in arena.
*/

RTP		ft_get_ind_num(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	RTP	offset;

	(void)carry;
	offset = ft_swap_endian(ft_get_bytecode(arena, pos), IND_SIZE);
	if (op_cont->mod)
		offset %= op_cont->mod;
	return (offset);
}

/*
**	These functions get the values hidden beneath it's respective containers:
**	of register type, instructions (ops) DIRectly or INDirectly pointed arena
**	content.
*/

RTP		ft_get_reg_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	(void)op_cont;
	return ((RTP)(carry->reg[arena[ft_calc_addr(pos)] - 1]));
}

RTP		ft_get_dir_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	(void)op_cont;
	(void)carry;
	return (ft_swap_endian(ft_get_bytecode(arena, pos), op_cont->t_dir_size));
}

RTP		ft_get_ind_val(uint8_t *arena, t_mop *op_cont, \
										t_carry *carry, intptr_t pos)
{
	intptr_t	offset;

	(void)carry;
	offset = (intptr_t)ft_swap_endian(ft_get_bytecode(arena, pos), IND_SIZE);
	if (op_cont->mod)
		offset %= op_cont->mod;
	return (ft_swap_endian(ft_get_bytecode(arena, carry->pos + offset), \
																	DIR_SIZE));
}
