/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_elem_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:19:07 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/12 19:21:52 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

int				main(void)
{
	t_carry		carry;
	t_carry		*ptr = &carry;

	ft_bzero(ptr, sizeof(carry));
	DEBzt(ptr->pos) DEBend()
	ptr->pos++;
	DEBzt(ptr->pos) DEBend()
}