/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwr_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:26:17 by mschimme          #+#    #+#             */
/*   Updated: 2021/03/14 17:18:35 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CWR_DEFS_H

# define CWR_DEFS_H
# include "cwr.h"
# include "op.h"

/*
**	Forbidden defines:
**	# define _INT_OVF(x) (int)(x) != x
**	# define DESC_BLOCK PROG_NAME_LENGTH + COMMENT_LENGTH
*/

# define _VALID_EXTENSION_ ".cor"

/*
**	KNOWN_OPS	- amount of operations, recognized by the VM.
**	OPC_SIZE	- size of OP_CODE entry on the arena (in bytes);
**	OPCB_SIZE	- size of operands coding byte entry on the arena (in bytes);
*/

# define KNOWN_OPS 17
# define OPC_SIZE 1
# define OPCB_SIZE 1

/*
**	Tested in t_calc_addr.c
**	Considered forbidden.
**	Reformed in function ft_calc_addr.
**	# define CALC_ADDR(x) (((x) % MEM_SIZE) + MEM_SIZE * ((x) < 0))
**	Reformed in function ft_step_size
**	# define STEP_SZ(x, y) ((x) == T_REG) + ((x) == T_DIR) * (y) + \
**															((x) == T_IND) * 2
**	Reformed in function ft_check_reg_is_valid
**	# define VALID_REG(x) (arena[CALC_ADDR(x)] > 0) * (arena[CALC_ADDR(x)] \
**																<= REG_NUMBER)
**	Reformed in function src/exec/the_cycle.c -> ft_eval_op_code_valid
**	# define VALID_OP_CODE(x, y) ((x) >= 0 && (x) < (y)) * (x)
*/

/*
**	DATA TYPE, which base is determined by op.h values.
*/

# if REG_SIZE < 5
#  define RTP int32_t
#  define URTP uint32_t
# else
#  define RTP int64_t
#  define URTP int64_t
# endif

# define _SEP_TYPE RTP

typedef struct s_world		t_world;
typedef struct s_champ		t_champ;
typedef struct s_carry		t_carry;
typedef struct s_cycle		t_cycle;
typedef struct s_error		t_error;
typedef struct s_vasa		t_vasa;
typedef struct s_dvasa		t_dvasa;
typedef struct s_mop			t_mop;
typedef void				t_err_rout(t_vasa **head, void *object);
typedef void				t_op_rout(t_world *nexus, t_carry *carry, \
										t_dvasa *head, t_dvasa **vacant);
typedef void				t_carry_cont_rout(t_dvasa *leafnode, \
												t_vasa *carry_cont);
typedef RTP					t_swap_endian_rout(RTP value);
typedef RTP					t_get_operand_val_rout(uint8_t *arena, \
								t_mop *op_cont, t_carry *carry, intptr_t pos);
typedef void				t_set_operand_val_rout(uint8_t *arena, \
								t_mop *op_cont, t_carry *carry, intptr_t pos);

# ifndef VASA_H
#  define VASA_H

/*
**	.cyc_sol		-	Number of cycle to perform -dump.
**	.cyc_arr		-	Pointer to pointers array. May be useless.
*/

union						u_generic
{
	void					*content;
	t_carry					*carry;
	t_error					*error;
	t_vasa					*vasa;
	size_t					cyc_sol;
	size_t					*cyc_arr;
};
# endif

typedef enum
{
	false,
	true
}	t_bool;

/*
**	Add '	uint8_t					TEMP_has_codebyte;' for t_calc_op_length
**	to get working.
*/

/*
**	.ops_amount;	-	Amount of operands.
**	.cd_byte		-	Presence of coding byte in the instruction.
**	.t_dir_size;	-	Size of t_dir for the op.
**	.ops_types[4];	-	Array to store operands' types.
**	.ops_length[4];	-	Array to store length of the operand.
**	.operands[4];	-	Value of the stored operand.
**	.length;		-	Total length of the op.
*/

struct						s_mop
{
	size_t					cooldown;
	intptr_t				mod;
	uint8_t					ops_amount;
	uint8_t					cd_byte;
	uint8_t					t_dir_size;
	uint8_t					ops_types[MAX_ARGS_NUMBER];
	uint8_t					ops_length[MAX_ARGS_NUMBER];
	RTP						operands[MAX_ARGS_NUMBER];
	intptr_t				length;
};

struct						s_vasa
{
	union u_generic			gen;
	size_t					content_size;
	struct s_vasa			*next;
};

/*
**	.argv_tar		-	Points to ARVG, a mistake is caused by.
*/

struct						s_error
{
	char					*argv_tar;
	char					*errmessage;
};

union						u_morph
{
	t_vasa					*un_vasa;
	t_dvasa					*du_vasa;
};

struct						s_dvasa
{
	union u_generic			gen;
	size_t					content_size;
	union u_morph			left;
	union u_morph			right;
};

/*
**	.cycle			-	Current cycle. //? Mb move to the function?
**	.next_check		-	Number of cycle when new 'alive' check shall be done.
**	.cyc_to_die		-	Current iterator of next_check.
**	.cycle_delta	-	A deincrementor for cyc_to_die, applied under conditions
**					involving .lives_done and .num_of_checks.
**	.lives_done		-	Counter of op_01_live; Resets after each live check.
**	.num_of_checks	-	Counter of checks performed. Resets after each live
**					check lead to cyc_to_die decrease.
**	.cyc_to_dump	-	Used to perform -dump flag.
*/

struct						s_cycle
{
	size_t					cycle;
	size_t					next_check;
	size_t					cyc_to_die;
	size_t					cycle_delta;
	size_t					lives_done;
	size_t					num_of_checks;
	t_vasa					*cyc_to_dump;
};

/*
**	.id				-	is set on carry initialization. Can't be changed.
**	.op				-	ОП-код операции, который был считан кареткой при
**					выполнении op_00_live. Выступает в качестве условного
**					оператора: Если (.op != 0), то каретка висела над текущим
**					ОП-кодом в ожидании истечения кулдауна инструкции. Если
**					(.op == 0), то каретка только перешла на текущую инструкцию
**					с предыдущего цикла (только исполнила предыдущую свою
**					инструкцию), ей необходимо встать на кулдаун по новой.
**	.last_live_op	-	Number of last cycle the carry were alive.
**	.exec_cyc		-	Number of the cycle of the op to be executed.
*/

struct						s_carry
{
	int						id;
	RTP						reg[REG_NUMBER];
	intptr_t				pos;
	t_mop					*op_cont;
	uint8_t					op;
	t_bool					carry_flag;
	size_t					last_live_op;
	size_t					exec_cyc;
	t_champ					*parent;
};

/*
**	WARNING! .name and .desc point to the same memory space, allocated as a
**	united memory chunk.
**
**	.body			-	ptr to champion's executable body (not on arena).
**	.size			-	nominal size (value parced from file, must be checked).
*/

struct						s_champ
{
	int32_t					id;
	t_bool					alive;
	RTP						size;
	char					*name;
	char					*desc;
	uint8_t					*body;
	size_t					last_live_op;
};

/*
**	.flags			-	Bitwise array of flags.
**		Description of each bit goes in descending: from the highest to lowest.
**		1:						0:
**		1:						0:
**		1:						0:
**		1:						0:
**		1:						0:
**		1:						0:
**		1:						0:
**		1:	Dump arena.			0:	Announce Battle victor.
**	.champ_ord		-	Массив указателей размера champs с отсартированными по
**					id чемпионами. champs[3]->id == 3, champs[2]->id == 2.
**	.survivor		-	Last champion declared he's alive;
**	.carry			-	Check code if still needed.
**	.errors			-	A head of regiestered errors chain.
*/

# define NEW_ARENA

# ifndef NEW_ARENA

struct						s_world
{
	char					*progname;
	uint8_t					flags;
	t_champ					champ[MAX_PLAYERS];
	t_champ					**champ_ord;
	int						champs;
	uint8_t					arena[MEM_SIZE];
	t_champ					*survivor;
	t_vasa					*carry;
	t_vasa					*errors;
	t_cycle					cyc;
};

# else

struct						s_world
{
	char					*progname;
	uint8_t					flags;
	t_champ					champ[MAX_PLAYERS];
	t_champ					**champ_ord;
	int						champs;
	uint8_t					arena[(MEM_SIZE + sizeof(RTP) * 2)];
	t_champ					*survivor;
	t_vasa					*carry;
	t_vasa					*errors;
	t_cycle					cyc;
};

# endif

/*
**	This is new version of t_world, configured to implement cycless and
**	conditionless extraction of the value of size RTP from arena.
*/

#endif
