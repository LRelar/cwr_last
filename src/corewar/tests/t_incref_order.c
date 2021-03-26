/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_incref_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:51:29 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/06 14:57:38 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>


int				main(void)
{
	t_cycle		t_cycs[2];
	t_cycle		*cyc_ptr = &t_cycs[0];

	ft_bzero(&t_cycs, sizeof(t_cycs));
	t_cycs[0].cyc_to_die = 1;
	t_cycs[1].cyc_to_die = 10;
	++(++cyc_ptr)->cyc_to_die;
	DEBlt(cyc_ptr->cyc_to_die) DEBend()
	return (0);
}