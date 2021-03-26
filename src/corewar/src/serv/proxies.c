/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proxies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:56:36 by mschimme          #+#    #+#             */
/*   Updated: 2020/12/26 14:07:38 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

int		ft_prox_err_ret(t_vasa **error_head, void *object, t_err_rout errfunc)
{
	errfunc(error_head, object);
	return (0);
}

void	ft_prox_err_malloc(const char *var, const char *par_func)
{
	ft_err_malloc((char *)var, par_func);
	ft_manage_world(NULL);
}
