/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_01_conv_1_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 22:12:46 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 18:32:14 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cwr.h>

RTP						ft_swap_endian_one(RTP value)
{
	return (
			((URTP)value & 0xFF) | \
			((((URTP)value & 0x80) >> 7) * (URTP)0xFFFFFFFFFFFFFF00));
}

RTP						ft_swap_endian_two(RTP value)
{
	return (
			(((URTP)value & 0x0000ff00) >> 8) | \
			(((URTP)value & 0x000000ff) << 8) | \
			((((URTP)value & 0x80) >> 7) * (URTP)0xFFFFFFFFFFFF0000));
}

RTP						ft_swap_endian_tri(RTP value)
{
	return (
			(((URTP)value & 0x00ff0000) >> 16) | \
			((URTP)value & 0x0000ff00) | \
			(((URTP)value & 0x000000ff) << 16) | \
			((((URTP)value & 0x80) >> 7) * (URTP)0xFFFFFFFFFF000000));
}

RTP						ft_swap_endian_qua(RTP value)
{
	return (
			(((URTP)value & 0xff000000) >> 24) | \
			(((URTP)value & 0x00ff0000) >> 8) | \
			(((URTP)value & 0x0000ff00) << 8) | \
			(((URTP)value & 0x000000ff) << 24) | \
			((((URTP)value & 0x80) >> 7) * (URTP)0xFFFFFFFF00000000));
}

RTP						ft_swap_endian(RTP value, uintptr_t size)
{
	static t_swap_endian_rout *arr[9] = {NULL, &ft_swap_endian_one, \
											&ft_swap_endian_two, \
											&ft_swap_endian_tri, \
											&ft_swap_endian_qua, \
											&ft_swap_endian_pen, \
											&ft_swap_endian_sex, \
											&ft_swap_endian_sep, \
											&ft_swap_endian_oct};

	return (arr[size](value));
}
