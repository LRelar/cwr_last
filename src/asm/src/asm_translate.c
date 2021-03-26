/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:38:53 by andru196          #+#    #+#             */
/*   Updated: 2020/09/25 00:43:44 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	print_stdout(char *rez, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((i % 16) == 0)
			ft_printf("\n%.7x ", i);
		if ((i % 2) == 1 && ((i + 1) % 16))
			ft_printf("%.2hhx ", rez[i]);
		else
			ft_printf("%.2hhx", rez[i]);
		i++;
	}
	ft_putendl("");
}

static int	zapisat(char *rez, char *file_name, int flag, size_t size)
{
	char	*file_name_cor;
	int		fd;

	if (!(flag & fl_stdout))
	{
		file_name_cor = ft_strreplacelast(file_name,
						SOURCE_EXTENSION, ASM_OUT_EXTENSION);
		fd = open(file_name_cor, O_WRONLY | O_CREAT, 3 << 7);
		free(file_name_cor);
		write(fd, rez, size);
		close(fd);
	}
	else
		print_stdout(rez, size);
	return (0);
}

int			asm_translate(t_asmcont *cont, char *file_name, int flag)
{
	char	*rez;
	size_t	size;

	if ((size = data_size(cont) + PROG_NAME_LENGTH +
								COMMENT_LENGTH + 4 * 4) > MEM_SIZE)
		return (PROGRAM_SIZE_LIMIT);
	if (fuck_connections(cont) < 0)
		return (CONNECTION_ERROR);
	if (!(rez = ft_strnew(size)))
		return (MALLOC_ERROR);
	if (0 > transofrm_data(cont, rez, size))
		return (-1);
	zapisat(rez, file_name, flag, size);
	free(rez);
	return (0);
}
