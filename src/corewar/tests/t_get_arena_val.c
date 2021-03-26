/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_get_arena_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:00:02 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/10 18:18:17 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#define	T_CWR_SIZE 2U

extern inline intptr_t	ft_calc_addr(intptr_t offset);
extern inline intptr_t	ft_step_size(uint8_t ops_type, uint8_t t_dir_size);
extern inline uint8_t	ft_check_reg_is_valid(uint8_t *arena, uintptr_t ptr);

#define CALC_ADDR ft_calc_addr

int32_t		bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size)
{
	int32_t		result;
	t_bool		sign;
	int			i;

	result = 0;
	sign = (t_bool)(arena[CALC_ADDR(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[CALC_ADDR(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[CALC_ADDR(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int				main(void)
{
	t_world		nexus;
	t_carry		carry;
	intptr_t	k = 4095;

	ft_bzero(&nexus, sizeof(nexus));
	ft_bzero(&carry, sizeof(carry));
	nexus.arena[sizeof(RTP) + 4095] = 0xff;
	nexus.arena[sizeof(RTP) + 0] = 0xfe;
	for (unsigned int i = 0; i < T_CWR_SIZE; i++)
	{
		carry.reg[0] |= (typeof(carry.reg[0]))nexus.arena[sizeof(RTP) + CALC_ADDR(k)] << (i * 8);
		k++;
	}
	carry.reg[0] = _SW_ENDIAN(carry.reg[0]);
	carry.reg[1] = bytecode_to_int32(&nexus.arena[sizeof(RTP) + 0], 4095, 2);
	return (0);
}