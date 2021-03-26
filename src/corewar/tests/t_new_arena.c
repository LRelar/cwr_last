/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_new_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:44:08 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/10 17:42:10 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*

*/

RTP				ft_get_value(uint8_t *arena, intptr_t offset)
{
	RTP			res;

	res = *(RTP *)(arena + offset) | *(RTP *)(arena - sizeof(RTP) + (((offset + sizeof(RTP)) % MEM_SIZE) * ((offset + sizeof(RTP)) / MEM_SIZE)));
	return (res);
}

int				main(void)
{
	t_world		nexus;
	t_carry		*carry = ft_memalloc(sizeof(t_carry));

	ft_bzero(&nexus, sizeof(nexus));
	ft_lstadd((t_list **)&nexus.carry, \
		ft_lstnew_r((const void *)carry, sizeof(t_carry)));
	nexus.carry->gen.carry->id = 1;
	nexus.carry->gen.carry->exec_cyc = 1;
	nexus.carry->gen.carry->pos = 0;

	nexus.arena[sizeof(RTP)] = 10;
	nexus.arena[sizeof(RTP) + 1] = 11;
	nexus.arena[sizeof(RTP) + 2] = 12;
	nexus.arena[sizeof(RTP) + 3] = 13;
	nexus.arena[(MEM_SIZE + sizeof(RTP) - 2)] = 0xFF;
	nexus.arena[(MEM_SIZE + sizeof(RTP) - 1)] = 0xFF;

	intptr_t	offset = 4090;
	uint8_t		*arena = &nexus.arena[0 + sizeof(RTP)];
	RTP			res;
	
	while (--offset > -100000)
	{
		res = ft_get_value(arena, ft_calc_addr(offset));
		if ((res != -16777216) && (res != -65536) && (res != 184549120) && \
			(res != 185270271) && (res != 202050303) && (res != 218893066) && \
			(res != 855051) && (res != 3340) && (res != 13) && (res != 0))
		{
			printf("WARNING! UNEXPECTED RESULT: %d, offset: %zu\n", res, offset);
			sleep(5);
		}
	}
	while (--offset > -10000)
	{
		res = ft_get_value(arena, ft_calc_addr(offset));
		if ((res != -16777216) && (res != -65536) && (res != 184549120) && \
			(res != 185270271) && (res != 202050303) && (res != 218893066) && \
			(res != 855051) && (res != 3340) && (res != 13) && (res != 0))
		{
			printf("WARNING! UNEXPECTED RESULT: %d, offset: %zu\n", res, offset);
			sleep(5);
		}
	}
	return (0);
}