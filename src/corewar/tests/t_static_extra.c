/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_static_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:49:27 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/12 17:53:24 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr_op.h>

void		ft_change_struct(int offset)
{
	static size_t	buff;

	buff = stat_opset[offset].cooldown;
	stat_opset[offset].cooldown = 1000;
}