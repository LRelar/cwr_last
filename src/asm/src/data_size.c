/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 00:04:18 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:29:40 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_otab[OP_TAB_SIZE];

size_t		data_size(t_asmcont *c)
{
	size_t		rez;
	size_t		cmd_size;
	size_t		i;
	int			j;

	rez = 0;
	i = -1;
	while (++i < c->cmd_count)
	{
		j = -1;
		cmd_size = 1 +
		(size_t)g_otab[c->command_list[i].cmnd_num].args_types_code;
		while (++j < g_otab[c->command_list[i].cmnd_num].args_num)
			if (c->command_list[i].arg_size[j] == T_REG)
				cmd_size += SIZE_REG;
			else if (c->command_list[i].arg_size[j] == T_IND)
				cmd_size += IND_SIZE;
			else
				cmd_size += DIR_SIZE /
				(g_otab[c->command_list[i].cmnd_num].t_dir_size + 1);
		c->command_list[i].size = cmd_size;
		rez += cmd_size;
	}
	return (rez);
}
