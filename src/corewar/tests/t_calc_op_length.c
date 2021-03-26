/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_calc_op_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:13:52 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 15:22:58 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr_op_defs.h>

int				main(void)
{
	intptr_t	size;
	uint32_t	i = UINT32_MAX;
	while (++i < KNOWN_OPS)
	{
		if (!stat_opset[i].TEMP_has_codebyte)
		{
			size = OPC_SIZE;
			for (int k = 0; k < stat_opset[i].ops_amount; k++)
				size += STEP_SZ(stat_opset[i].ops_types[k], stat_opset[i].t_dir_size);
			DEBmesst("Instruction code:") DEBuintt(i) DEBend()
			DEBuintt(size) DEBend()
		}
	}
	return (0);
}