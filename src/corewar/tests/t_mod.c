/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:35:46 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/25 12:37:27 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>


int						main(void)
{
	int					i = -730;

	i %= IDX_MOD;
	ft_printf("\'i\' after MOD operation: %d\n", i);
	return (0);
}