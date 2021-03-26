/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_cor_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:08:33 by andru196          #+#    #+#             */
/*   Updated: 2020/09/23 23:41:50 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	init_container(t_asmcont *cont)
{
	ft_bzero(cont, sizeof(t_asmcont));
	cont->command_list = ft_memalloc(sizeof(t_command) * (MAX_COMMANDS));
	return (!cont->command_list);
}
