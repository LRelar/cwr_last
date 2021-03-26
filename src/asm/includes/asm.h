/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:14:38 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:27:06 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <fcntl.h>
# include "op.h"

# include "sfalif_libft.h"
# include "libft.h"
# include "cli_helper.h"

# include "corewar_error.h"

# define BUF_COR_SIZE 500
# define SIZE_REG 1

# define MAX_COMMANDS	CHAMP_MAX_SIZE / 2
# define MAX_WORD_LEN	64
# define SOURCE_UPEXTENSION ".S"

# define QUOTE_CHAR				'"'

typedef struct s_row				t_row;
typedef struct s_command			t_command;
typedef struct s_label				t_label;
typedef struct s_cmnd_label_link	t_cmnd_label_link;
typedef struct s_asmcont			t_asmcont;
typedef enum e_args					t_args;

struct				s_row
{
	char			has_label;
	t_command		*cmd;
	char			arg_num;
};

enum				e_args
{
	fl_nono = 0,
	fl_stdout = 1,
	fl_strict = 2,
	fl_sum = 4
};

int					g_flag;

struct				s_command
{
	unsigned char		cmnd_num;
	unsigned char		arg_size[MAX_ARGS_NUMBER];
	unsigned char		is_lbl[MAX_ARGS_NUMBER];
	long long			arg[MAX_ARGS_NUMBER];
	int					row;
	unsigned char		size;
};

struct				s_label
{
	char				name[MAX_WORD_LEN + 1];
	t_command			*dst;
	int					row;
	t_label				*next;
};

struct				s_cmnd_label_link
{
	t_label				*label;
	t_command			*command;
	size_t				arg_num;
	size_t				col;
	t_cmnd_label_link	*next;
};

struct				s_asmcont
{
	char				*champ_name;
	char				*comment;
	size_t				cmd_count;
	t_command			*command_list;
	t_label				*label_list;
	t_cmnd_label_link	*conn_list;
};

int					g_error_code;
int					g_column;
int					g_row;

int					check_flags(char **argv, int argc, char *flag);
int					cor_open_file(char *file_name, int flag);
void				asm_print_error();
int					init_container(t_asmcont *cont);
t_cmnd_label_link	*new_connect(t_asmcont *cont, int arg_n, char *lbl_name);
t_label				*new_label(t_asmcont *cont, char *str);
int					new_command(t_asmcont *cont, int command);
int					cpy_word(char *dst, char *src);
int					cpy_arg_word(char *dst, char *src);
int					label_check(t_asmcont *c, char *word, int len);
int					command_check(t_asmcont *cont, char *word, char **tr,
																int len);
void				skip_space(char **str);
int					asm_translate(t_asmcont *cont, char *file_name, int flag);
void				prepare_arg(char *word, long long *arg);
void				ast_strrtrim(char *word);
int					special_arg(t_asmcont *c, int dst, char **str, int fd);
int					args_check(t_asmcont *cont, int com_pos, int arg_num,
															char *word);
int					label_check(t_asmcont *c, char *word, int len);
int					digits_count(char *str);
t_cmnd_label_link	*add_label_arg(t_asmcont *c, char *wrd, int arg_n);
int					arg_label_check(char *wrd);
char				skip_num(char **wrd, long long num);
void				skip_first_part(char **word);
size_t				data_size(t_asmcont *c);
int					fuck_connections(t_asmcont *c);
int					transofrm_data(t_asmcont *cont, char *rez, unsigned size);
long long			rev_bytes_ll(long long n);

#endif
