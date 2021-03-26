/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_02_conv_5-8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:37:00 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 18:38:45 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cwr.h>

RTP						ft_swap_endian_pen(RTP value)
{
	return (
			(((uint64_t)value & 0x000000ff00000000) >> 32) | \
			(((uint64_t)value & 0x00000000ff000000) >> 16) | \
			((uint64_t)value  & 0x0000000000ff0000) | \
			(((uint64_t)value & 0x000000000000ff00) << 16) | \
			(((uint64_t)value & 0x00000000000000ff) << 32) | \
			((((uint64_t)value & 0x80) >> 7) * (uint64_t)0xFFFFFF0000000000));
}

RTP						ft_swap_endian_sex(RTP value)
{
	return (
			(((uint64_t)value & 0x0000ff0000000000) >> 40) | \
			(((uint64_t)value & 0x000000ff00000000) >> 24) | \
			(((uint64_t)value & 0x00000000ff000000) >> 8) | \
			(((uint64_t)value & 0x0000000000ff0000) << 8) | \
			(((uint64_t)value & 0x000000000000ff00) << 24) | \
			(((uint64_t)value & 0x00000000000000ff) << 40) | \
			((((uint64_t)value & 0x80) >> 7) * (uint64_t)0xFFFF000000000000));
}

RTP						ft_swap_endian_sep(RTP value)
{
	return (
			(((uint64_t)value & 0x00ff000000000000) >> 48) | \
			(((uint64_t)value & 0x0000ff0000000000) >> 32) | \
			(((uint64_t)value & 0x000000ff00000000) >> 16) | \
			((uint64_t)value & 0x00000000ff000000) | \
			(((uint64_t)value & 0x0000000000ff0000) << 16) | \
			(((uint64_t)value & 0x000000000000ff00) << 32) | \
			(((uint64_t)value & 0x00000000000000ff) << 48) | \
			((((uint64_t)value & 0x80) >> 7) * (uint64_t)0xFF00000000000000));
}

RTP						ft_swap_endian_oct(RTP value)
{
	return (
			(((uint64_t)value & 0xff00000000000000) >> 56) | \
			(((uint64_t)value & 0x00ff000000000000) >> 40) | \
			(((uint64_t)value & 0x0000ff0000000000) >> 24) | \
			(((uint64_t)value & 0x000000ff00000000) >> 8) | \
			(((uint64_t)value & 0x00000000ff000000) << 8) | \
			(((uint64_t)value & 0x0000000000ff0000) << 24) | \
			(((uint64_t)value & 0x000000000000ff00) << 40) | \
			(((uint64_t)value & 0x00000000000000ff) << 56));
}
