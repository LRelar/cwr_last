/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_endian_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 08:23:43 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/11 18:40:30 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

extern RTP		ft_get_bytecode(uint8_t *arena, intptr_t offset);
intptr_t		ft_calc_addr(intptr_t offset);

/*
**	ЕБАНЫЙ РОТ ЭТОГО КАЗИНО!
base_mask = (URTP)0xFFFFFFFFFFFFFFFF >> ((sizeof(RTP) - size) * 8);
Дает -1 при size == 3, sizeof(RTP) == 8.
base_mask = (URTP)(0xFFFFFFFFFFFFFFFF >> ((sizeof(RTP) - size) * 8));
Дает ожидаемое значение.
URTP: unsigned long;
URTP base_mask;
пачиму?
*/

void		ft_set_bytecode(uint8_t	*arena, intptr_t offset, RTP value, 
																uint8_t size)
{
	URTP			base_mask;
	URTP			arena_mask;
	intptr_t	magic;
	
	offset = ft_calc_addr(offset);
	magic = ((offset + sizeof(RTP)) % MEM_SIZE) * \
											((offset + sizeof(RTP)) / MEM_SIZE);
	base_mask = (URTP)(0xFFFFFFFFFFFFFFFF >> ((sizeof(RTP) - size) * 8));
	arena_mask = (URTP)(0xFFFFFFFFFFFFFFFF << (size * 8));
	value = (ft_swap_endian(value, (uintptr_t)size) & base_mask) | \
								(ft_get_bytecode(arena, offset) & arena_mask);
	*(RTP *)(arena + offset) = value & (0xFFFFFFFFFFFFFFFF >> (8 * magic));
	*(RTP *)(arena - sizeof(RTP) + magic) = value & \
					(0xFFFFFFFFFFFFFFFF << (8 * (sizeof(RTP) - magic)));
}

int						main(void)
{
	RTP					source;
	uint8_t				buffer[16 + (sizeof(RTP) * 2)];

	ft_bzero(&buffer[0], sizeof(buffer));
	buffer[sizeof(RTP)] = 0xAA;
	buffer[sizeof(RTP) + 1] = 0xAB;
	*(int *)&buffer[sizeof(RTP) + 16 - 4] = 0xDDDDDDDD;
	source = 0xECCCFF;
	ft_set_bytecode(&buffer[sizeof(RTP)], + 16 - 2, source, 3);
	return (0);
}