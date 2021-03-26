/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_op_04_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:10:12 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/22 22:16:13 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
sh ./t_compiler.sh t_op_04_add "./src/op/op_04_add.c ./src/op/op_cont.c ./src/op/arena_get.c ./src/flip_endian/end_01_conv_1_4.c ./src/flip_endian/end_02_conv_5-8.c ./src/exec/get_operands.c"
*/

#define AR_START 10
#define SCENARIO_1 "\x04\x54\x06\x05\x01\x04\xE4\x00\x00\x00\x00\x00\x00\x00\x04\x54\x05\x07\x02"


static void				tft_prepare(t_world *nexus)
{
	t_carry				*carry;

	carry = ft_memalloc(sizeof(t_carry));
	ft_lstadd((t_list **)&(nexus->carry), \
				ft_lstnew_r((const void *)carry, sizeof(t_carry)));
	carry->pos = AR_START;
	carry->reg[5 - 1] = 30;
	carry->reg[6 - 1] = 70;
	carry->reg[7 - 1] = 31;
}

static void				tft_place_codes(uint8_t *arena, intptr_t offset, \
													size_t size, uint8_t *string)
{
	ft_memcpy(arena + offset, string, size);
}

int						main(void)
{
	t_world				nexus;
	uint8_t				*arena;
	

	ft_bzero(&nexus, sizeof(nexus));
	arena = &(nexus.arena[sizeof(RTP)]);
	tft_prepare(&nexus);
	tft_place_codes(arena, AR_START, sizeof(SCENARIO_1) - 1, SCENARIO_1);
	op_add(&nexus, nexus.carry->gen.carry, NULL, NULL);
	op_add(&nexus, nexus.carry->gen.carry, NULL, NULL);
	op_add(&nexus, nexus.carry->gen.carry, NULL, NULL);
	return (0);
}