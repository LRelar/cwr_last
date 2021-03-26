/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_static_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:42:41 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/12 17:55:14 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

void		ft_change_struct(int offset);
size_t		*ft_get_value(int offset);



void		ft_change_value(size_t *ptr)
{
	*ptr = 100500;
}

int			main(void)
{
	size_t	*st_ptr = ft_get_value(5);

	ft_change_value(st_ptr);
	ft_change_struct(5);

	return(0);
}