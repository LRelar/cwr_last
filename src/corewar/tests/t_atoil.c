/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_atoil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:04:01 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/15 21:19:13 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <libft.h>

int			main(void)
{
	char	*longmax = "9223372036854775807";
	char	*longmin = "-9223372036854775808";
	char	*overflow = "9223374036854775809";
	char	*underflow = "-9223572036854775811";
	uint8_t	flag = 0;

	long long std = strtoll(longmax, NULL, 0);
	long long ctm = ft_atol_r(longmax, &flag);

	std = ctm = 0;
	flag = 0;
	std = strtoll(longmin, NULL, 0);
	ctm = ft_atol_r(longmin, &flag);

	flag = 0;
	std = ctm = 0;
	std = strtoll(overflow, NULL, 0);
	ctm = ft_atol_r(overflow, &flag);

	std = ctm = 0;
	flag = 0;
	std = strtoll(underflow, NULL, 0);
	ctm = ft_atol_r(underflow, &flag);

	flag = 0;
	ctm = ft_atol_r(NULL, &flag);

	return (0);
}