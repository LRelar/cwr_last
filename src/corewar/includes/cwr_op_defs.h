/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwr_op_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:27:01 by mschimme          #+#    #+#             */
/*   Updated: 2021/03/14 17:17:53 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CWR_OP_DEFS_H

# define CWR_OP_DEFS_H
# define CYC_COEFF 1 
#include <cwr.h>


/*
**	Structure for holding crucial parameters of each operation, performed via
**	op-functions.
**	cooldown	--- stores data about amount of cycles to be passed untill op is
**		performed since its op-code is read.
**	ops_amount	--- stores data about amount of operands given op have to deal
**		with.
**	t_dir_size	--- stores data about size of T_DIR for given op.
**	ops_types	---	array storing data about retreieved operand configuration.
?	operands	--- arrayf of vars-sontainers for parsed(loaded) values.
*/

const static uint8_t		stat_code_to_type[5] = {
	0, T_REG, T_DIR, T_IND
};
/*
**	Size (.length) of each instruction with no coding byte is calculated in 
**	t_calc_op_length test.
*/
const static t_mop			stat_opset[17] = {
	{							//*00_my_read;
		.cooldown = 1,
		.ops_amount = 0,
		.t_dir_size = 0,
		.ops_types = {0, 0, 0, 0},
		.operands = {0, 0, 0, 0},
		.length = OPC_SIZE,
		.mod = 0
	},
	{							//*01_live;
		.cooldown = 10 - CYC_COEFF,
		.ops_amount = 1,
		.t_dir_size = 4,
		.ops_types = {T_DIR},
		.ops_length = { 4 },
		.length = 5,
		.mod = 0
	},
	{							//*02_ld;
		.cooldown = 5 - CYC_COEFF,
		.ops_amount = 2,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_DIR | T_IND, T_REG},
		.mod = IDX_MOD
	},
	{							//*03_st;
		.cooldown = 5 - CYC_COEFF,
		.ops_amount = 2,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_REG, T_REG | T_IND},
		.mod = IDX_MOD
	},
	{							//*04_add;
		.cooldown = 10 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_REG, T_REG, T_REG},
		.mod = 0
	},
	{							//*05_sub;
		.cooldown = 10 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_REG, T_REG, T_REG},
		.mod = 0
	},
	{							//*06_and;
		.cooldown = 6 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.mod = IDX_MOD
	},
	{							//*07_or;
		.cooldown = 6 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.mod = IDX_MOD
	},
	{							//*08_xor;
		.cooldown = 6 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.mod = IDX_MOD
	},
	{							//*09_zjmp;
		.cooldown = 20 - CYC_COEFF,
		.ops_amount = 1,
		.t_dir_size = 2,
		.length = 3,
		.ops_types = {T_DIR},
		.mod = IDX_MOD
	},
	{							//*10_ldi;
		.cooldown = 25 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 2,
		.ops_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.mod = IDX_MOD
	},
	{							//*11_sti;
		.cooldown = 25 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 2,
		.ops_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.mod = IDX_MOD
	},
	{							//*12_fork;
		.cooldown = 800 - CYC_COEFF,
		.ops_amount = 1,
		.t_dir_size = 2,
		.length = 3,
		.ops_types = {T_DIR},
		.mod = IDX_MOD
	},
	{							//*13_lld;
		.cooldown = 10 - CYC_COEFF,
		.ops_amount = 2,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_DIR | T_IND, T_REG},
		.mod = 0
	},
	{							//*14_lldi;
		.cooldown = 50 - CYC_COEFF,
		.ops_amount = 3,
		.cd_byte = 1,
		.t_dir_size = 2,
		.ops_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.mod = IDX_MOD
	},
	{							//*15_lfork;
		.cooldown = 1000 - CYC_COEFF,
		.ops_amount = 1,
		.t_dir_size = 2,
		.length = 3,
		.ops_types = {T_DIR}
	},
	{							//*16_aff;
		.cooldown = 2 - CYC_COEFF,
		.ops_amount = 1,
		.cd_byte = 1,
		.t_dir_size = 4,
		.ops_types = {T_REG},
		.mod = 0
	}
};

#endif
