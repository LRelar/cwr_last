/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_calc_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:17:33 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 14:39:01 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr_op_defs.h>

#define CALC_ADDR ft_calc_addr

int32_t		calc_addr(int32_t addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	return (addr);
}

int				main(void)
{
	int			k = 0;
	int			modif = 5;

	int			x = CALC_ADDR(k - modif);
	int			y = calc_addr(k - modif);
	return (x + y);
}