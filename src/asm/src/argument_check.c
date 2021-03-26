/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 23:33:47 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/10/31 19:40:43 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

extern t_op	g_otab[OP_TAB_SIZE];

int			args_ind_dir(t_asmcont *cont, int com_pos, int arg_num, char *word)
{
	long long	rez;
	char		flag;

	flag = *word == DIRECT_CHAR ? T_DIR : T_IND;
	if (!(g_otab[cont->command_list[com_pos].cmnd_num].args_types[arg_num]
		& flag))
		return (-1);
	rez = 0;
	if (*(word + (flag == T_DIR)) == LABEL_CHAR)
	{
		if (!arg_label_check(word + 1 + (flag == T_DIR)))
			return (-1);
		add_label_arg(cont, word + 1 + (flag == T_DIR), arg_num);
		cont->command_list[com_pos].is_lbl[arg_num] = 1;
	}
	else
	{
		rez = ft_atoix(word + (flag == T_DIR));
		if ((!str_num_eq(rez, word + (flag == T_DIR)) && (g_flag & fl_strict))
		|| (!(g_flag & fl_strict) && !ft_isnumber(word + (flag == T_DIR))))
			return (-1);
	}
	cont->command_list[com_pos].arg[arg_num] += rez;
	cont->command_list[com_pos].arg_size[arg_num] = flag;
	return (0);
}

static int	check_regnumber(int regs[REG_NUMBER][2], int number)
{
	int			i;
	static char	flag = 0;

	i = 0;
	if (flag || flag++)
		while (i < REG_NUMBER)
			regs[i++][1] = 0;
	i = 0;
	while (i < REG_NUMBER)
	{
		if (!regs[i][1])
		{
			regs[i][0] = number;
			regs[i][1] = 1;
		}
		if (number == regs[i][0] && regs[i][1])
			return (1);
		i++;
	}
	return (0);
}

static int	is_norm_pos(t_asmcont *cont, int com_pos, int arg_num, char *word)
{
	return (arg_num + 1 < g_otab[cont->command_list[com_pos].cmnd_num].args_num
	&& word[ft_strlen(word) - 1] != SEPARATOR_CHAR)
	|| (word[ft_strlen(word) - 1] == SEPARATOR_CHAR
	&& arg_num + 1 == g_otab[cont->command_list[com_pos].cmnd_num].args_num);
}

static int	is_finished_and_type(t_asmcont *cont, int com_pos,
											int arg_num, char *word)
{
	return ((word[digits_count(word)] != SEPARATOR_CHAR
	&& word[digits_count(word)] != '\0')
	|| !(g_otab[cont->command_list[com_pos].cmnd_num].args_types[arg_num]
	& T_REG));
}

int			args_check(t_asmcont *cont, int com_pos, int arg_num, char *word)
{
	long long	rez;
	const char	sep[2] = {SEPARATOR_CHAR, '\0'};
	static int	registers[REG_NUMBER][2];

	rez = 0;
	if (is_norm_pos(cont, com_pos, arg_num, word))
		return (-1);
	if (ft_strendwith(word, (char *)sep))
		word[ft_strlen(word) - 1] = '\0';
	prepare_arg(word, &(cont->command_list[com_pos].arg[arg_num]));
	ast_strrtrim(word);
	if (*word == 'r')
	{
		if (!check_regnumber(registers, rez = ft_atoi(++word)) || rez < 0
	|| is_finished_and_type(cont, com_pos, arg_num, word))
			return (-1);
		cont->command_list[com_pos].arg_size[arg_num] = T_REG;
		cont->command_list[com_pos].arg[arg_num] += rez;
	}
	else if (args_ind_dir(cont, com_pos, arg_num, word) < 0)
		return (-1);
	return (0);
}
