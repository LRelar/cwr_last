/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_non.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:59:06 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/18 16:01:54 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

int						main(void)
{
	t_carry				carry;

	ft_bzero(&carry, sizeof(carry));
	carry.reg[0] = 2;
	carry.carry_flag = (t_bool)(!carry.reg[0]);

	ft_printf("%d\n", carry.carry_flag);
	return (0);
}