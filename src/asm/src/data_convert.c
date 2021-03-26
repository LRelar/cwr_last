/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 00:10:25 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/09/25 00:45:02 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_otab[OP_TAB_SIZE];

char						type_code(t_command *cmd)
{
	char rez;

	rez = 0;
	if (cmd->arg_size[0] == T_REG)
		rez |= REG_CODE << 6;
	else if (cmd->arg_size[0] == T_IND)
		rez |= IND_CODE << 6;
	else if (cmd->arg_size[0] == T_DIR)
		rez |= DIR_CODE << 6;
	if (cmd->arg_size[1] == T_REG)
		rez |= REG_CODE << 4;
	else if (cmd->arg_size[1] == T_IND)
		rez |= IND_CODE << 4;
	else if (cmd->arg_size[1] == T_DIR)
		rez |= DIR_CODE << 4;
	if (cmd->arg_size[2] == T_REG)
		rez |= REG_CODE << 2;
	else if (cmd->arg_size[2] == T_IND)
		rez |= IND_CODE << 2;
	else if (cmd->arg_size[2] == T_DIR)
		rez |= DIR_CODE << 2;
	return (rez);
}

void						write_n_num(char **dst, long long n,
											unsigned char bytes)
{
	int i;

	if (n >= ((long long)1 << bytes * 8))
		n %= 1 << ((long long)bytes * 8 - 1);
	i = 0;
	n = rev_bytes_ll(n);
	i = sizeof(long long) - bytes;
	bytes = sizeof(long long);
	while (bytes > i)
	{
		**dst = *(((char *)&n) + i++);
		(*dst)++;
	}
}

static unsigned long long	set_number(long long n, unsigned char size,
									unsigned char t_dir_size)
{
	long long	tmp;

	if (size == T_REG)
		size = SIZE_REG;
	else if (size == T_IND)
		size = IND_SIZE;
	else
		size = DIR_SIZE / (1 + t_dir_size);
	tmp = ft_maxint(size, n > 0);
	if ((n >= 0 && n < tmp) || (n < 0 && (-tmp - 1) < n))
		tmp = n;
	else if ((n < 0 && (-tmp - 1) >= n)
		|| (n > 0 && tmp <= n))
		tmp = n & (tmp + ((tmp + 1) == -n));
	return (tmp);
}

int							write_cmnd(char *dst, t_command *cmd)
{
	int					i;
	char				*cpy;
	unsigned long long	num;

	cpy = dst;
	*dst++ = cmd->cmnd_num + 1;
	if (g_otab[cmd->cmnd_num].args_types_code)
		*dst++ = type_code(cmd);
	i = -1;
	while (++i < g_otab[cmd->cmnd_num].args_num)
	{
		num = set_number(cmd->arg[i], cmd->arg_size[i],
							g_otab[cmd->cmnd_num].t_dir_size);
		if (cmd->arg_size[i] == T_REG)
			write_n_num(&dst, num, SIZE_REG);
		else if (cmd->arg_size[i] == T_IND)
			write_n_num(&dst, num, IND_SIZE);
		else if (cmd->arg_size[i] == T_DIR)
			write_n_num(&dst, num, DIR_SIZE /
							(1 + g_otab[cmd->cmnd_num].t_dir_size));
	}
	return (dst - cpy);
}

int							transofrm_data(t_asmcont *cont, char *rez,
														unsigned size)
{
	size_t			i;
	size_t			j;

	write_n_num(&rez, COREWAR_EXEC_MAGIC, sizeof(int));
	rez -= sizeof(int);
	i = 0 + sizeof(int);
	ft_strncpy(rez + i, cont->champ_name, PROG_NAME_LENGTH);
	i += PROG_NAME_LENGTH;
	*(int *)(rez + i) = 0;
	i += sizeof(int);
	rez += i;
	write_n_num(&rez, size - PROG_NAME_LENGTH -
							COMMENT_LENGTH - 16, sizeof(int));
	rez -= sizeof(int) + i;
	i += sizeof(unsigned);
	if (cont->comment)
		ft_strncpy(rez + i, cont->comment, COMMENT_LENGTH);
	i += COMMENT_LENGTH;
	*(int *)(rez + i) = 0;
	i += sizeof(int);
	j = 0;
	while (j < cont->cmd_count)
		i += write_cmnd(rez + i, &cont->command_list[j++]);
	return (0);
}
