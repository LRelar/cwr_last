/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_defcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:45:24 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/20 15:11:15 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

int			main(void)
{
	t_world huynya;
	t_error	err = {
		.argv_tar = "WTF!?",
		.errmessage = "GFYS"
	};
	
	t_vasa	error = {
		.content_size = 0,
		.gen.error = &err,
		.next = NULL
	};
	ft_bzero(&huynya, sizeof(huynya));
	huynya.errors = &error;
	DEBtextt(huynya.errors->gen.error->errmessage) DEBend()

	return (0);
}