/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwr_funcs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:21:22 by mschimme          #+#    #+#             */
/*   Updated: 2020/12/26 14:08:26 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CWR_FUNCS_H
# define CWR_FUNCS_H
# include "cwr.h"

/*
******************		prep_rout (parsing) funcs:		************************
*/

void		ft_read_params(char ***argv, t_world *nexus);
uint8_t		ft_scan_lines(char ***argv, t_world *nexus);
uint8_t		ft_parse_fdump(char ***argv, t_world *nexus);
uint8_t		ft_parse_champ(char ***argv, int id, t_world *nexus);
int			ft_get_n_flag(char ***argv, t_world *nexus);
int			ft_read_champ_file(char *file, int id, t_champ *this, \
														t_vasa **last_error);
void		ft_init_champ(t_champ *this, int id, t_vasa **champ_error);
uint8_t		*ft_champ_body_alloc(size_t ch_size, t_vasa **champ_err);
void		ft_clear_champ(t_champ *this);
uint8_t		ft_supervise_input(t_world *nexus, int ch_amount);
void		ft_prep_battle(t_world *nexus);
void		ft_check_id(t_vasa **errors_head, t_champ *champs, int ch_amount);

/*
******************			exec(ution) funcs:			************************
*/

void		ft_exec_battle(t_world *nexus);
void		ft_the_dump_cycle(t_world *nexus, t_dvasa *tree);
void		ft_the_cycle(t_world *nexus, t_dvasa *tree);

/*
******************				SERVice funcs:			************************
*/

int			ft_are_digits(const char *str);
int			ft_are_ndigits(const char *start, const char *end);

void		ft_manage_world(t_world *nexus);
void		ft_wipe_champs(t_champ *ptr);
uint8_t		ft_ask_user(char *msg);

/*
**	ft_del_carry	- Пока не нужна, используется ft_del.
**	ft_del_error	- Пока не нужна, используется ft_del.
*/

void		ft_del_carry(void *ptr, size_t size);
void		ft_del_error(void *ptr, size_t size);
int			ft_prox_err_ret(t_vasa **error_head, void *object, \
															t_err_rout errfunc);
void		ft_prox_err_malloc(const char *var, const char *par_func);
int			ft_cyc_left_grt_right(void *a, void *b);
int			ft_cyc_left_lsr_right(void *a, void *b);
t_champ		**ft_build_champarr_sorted(t_champ *champ_arr, int champs);
int			ft_camp_p_leftid_grt_rightid(void *left, void *right);

/*
******************				errors funcs:			************************
** Are not supposed to allocate memory for error messages.
*/
void		ft_show_man(void);
void		ft_err_fdump_notnbr(t_vasa **head, void *object);
void		ft_err_fdump_inter(t_vasa **head, void *object);
void		ft_err_fn_notnbr(t_vasa **head, void *object);
void		ft_err_fn_inter(t_vasa **head, void *object);
void		ft_err_not_champ(t_vasa **head, void *object);
void		ft_err_nochamps(t_vasa **head, void *object);
void		ft_err_invalid_filename(t_vasa **head, void *object);
void		ft_err_invalid_parameter(t_vasa **head, void *object);
void		ft_err_champ_limit(t_vasa **head, void *object);
void		ft_err_id_doubled(t_vasa **head, void *object);
void		ft_err_id_behind_fighters(t_vasa **head, void *object);
void		ft_show_compconf(void);

/*
******************		Champion parsing errors funcs:	************************
** Are not supposed to allocate memory for error messages.
*/
int			ft_ch_err_manager(char *filename, t_vasa **subchain_head, \
											t_vasa **chain_head, t_champ *this);
void		ft_err_invalid_cwr_magic(t_vasa **last, void *object);
void		ft_err_invalid_name(t_vasa **last, void *object);
void		ft_err_invalid_filesize(t_vasa **last, void *object);
void		ft_err_invalid_champsize(t_vasa **last, void *object);
void		ft_err_invalid_separator(t_vasa **head, void *object);
void		ft_err_invalid_comment(t_vasa **head, void *object);
void		ft_err_invalid_bodysize(t_vasa **head, void *object);

/*
******************		Carry (cursor) managing funcs:	************************
*/

t_carry		*ft_create_carry(void);
void		ft_init_carries(t_world *nexus);
t_carry		*ft_dupe_carry(t_carry *parent);
void		ft_carry_ins_by_id(t_dvasa *leafnode, t_vasa *carry_cont);

/*
******************			Tree managing funcs:		************************
*/

t_dvasa		*ft_create_leafnode(void const *content, size_t content_size);
t_dvasa		*ft_create_leafnode_r(void const *content, size_t content_size);
void		ft_add_offspring_by_order(t_dvasa *leaf, t_vasa *new);
void		ft_add_offspring_by_id(t_dvasa *leaf, t_vasa *new);
void		ft_add_leafnode(t_dvasa **aleaf, t_dvasa *new);
void		ft_del_leafnode(t_dvasa **aleaf);
void		ft_destroy_leaftree(t_dvasa **aleaf, t_dvasa **vacant);
void		ft_tree_undertaker(t_dvasa **aleaf, t_dvasa **vacan, t_cycle *cyc);
void		ft_leafnode_pick(t_vasa *carry_cont, t_dvasa *tree, \
								t_dvasa **new_node, t_carry_cont_rout *manager);
void		ft_leafnode_vacate(t_dvasa **tree, t_dvasa **vacant);

/*
******************			OP-performing funcs:		************************
*/

/*
**	WARNING! If you add new operation, update op_tab of ft_process_carry and
**	KNOWN_OPS.
*/

void		op_new_op(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_live(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_ld(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_st(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_add(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_sub(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_and(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_or(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_xor(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_zjmp(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_ldi(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_sti(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_fork(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_lld(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_lldi(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_lfork(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);
void		op_aff(t_world *nexus, t_carry *carry, t_dvasa *head, \
														t_dvasa **vacant);

/*
******************			OP-support funcs:			************************
*/

const t_mop	*ft_get_op_cont(uint8_t offset);
void		ft_clone_op_cont(uint8_t offset, t_mop *ptr);
uint8_t		ft_eval_operands_type(uint8_t *arena, intptr_t ptr, \
									t_mop *ops_cont, const t_mop *const ref);
intptr_t	ft_calc_addr(intptr_t offset);
intptr_t	ft_step_size(uint8_t ops_type, uint8_t t_dir_size);
uint8_t		ft_check_reg_is_valid(uint8_t *arena, uintptr_t ptr);
extern RTP	ft_get_bytecode(uint8_t *arena, intptr_t offset);
void		ft_set_bytecode(uint8_t	*arena, intptr_t offset, RTP value, \
																uint8_t size);
void		ft_eval_operands_length(uint8_t *arena, intptr_t pos, \
																t_mop *op_cont);

/*
******************			manage operands:			************************
*/

void		ft_get_operands(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
															intptr_t amount);
RTP			ft_get_reg_num(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
RTP			ft_get_ind_num(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
RTP			ft_get_reg_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
RTP			ft_get_dir_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
RTP			ft_get_ind_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
RTP			ft_get_nil_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
void		ft_set_nil_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
void		ft_set_reg_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
void		ft_set_dir_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);
void		ft_set_ind_val(uint8_t *arena, t_mop *op_cont, t_carry *carry, \
																intptr_t pos);

/*
******************			swap endian funcs:			************************
*/

RTP			ft_swap_endian(RTP value, uintptr_t size);
RTP			ft_swap_endian_one(RTP value);
RTP			ft_swap_endian_two(RTP value);
RTP			ft_swap_endian_tri(RTP value);
RTP			ft_swap_endian_qua(RTP value);
RTP			ft_swap_endian_pen(RTP value);
RTP			ft_swap_endian_sex(RTP value);
RTP			ft_swap_endian_sep(RTP value);
RTP			ft_swap_endian_oct(RTP value);

/*
******************			output funcs:				************************
*/

uint8_t		ft_print_dump(t_world *nexus);
void		ft_print_outro(t_champ *survivor);

/*
******************			Built-in test funcs:		************************
*/

#endif
