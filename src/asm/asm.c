/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andru196 <andru196@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:59:01 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/06/28 19:18:37 by andru196         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_error ()
{
	char	*err[2];
	
	err[0] = g_error_code ? "COMPILATION ERROR %d\n%s\nLine: %d, %d\n"
	: "COMPILATION ERROR %d\n";
	if (g_error_code == MALLOC_ERROR)
		err[1] = MALLOC_ERROR_STR;
	if (g_error_code == SOURCE_EXTENSION_ERROR)
		err[1] = SOURCE_EXTENSION_ERROR_STR;
	if (g_error_code == OPEN_FILE_ERROR)
		err[1] = OPEN_FILE_ERROR_STR;
	if (g_error_code == LABEL_SIZE_ERROR)
		err[1] = LABEL_SIZE_ERROR_STR;
	if (g_error_code == LABEL_FORBIDDEN_CHAR)
		err[1] = LABEL_FORBIDDEN_CHAR_STR;
	if (g_error_code == COMMAND_NOT_FOUND)
		err[1] = COMMAND_NOT_FOUND_STR;
	if (g_error_code == ARGS_ERROR)
		err[1] = ARGS_ERROR_STR;
	if (g_error_code == PROGRAM_SIZE_LIMIT)
		err[1] = PROGRAM_SIZE_LIMIT_STR;
	if (g_error_code == CONNECTION_ERROR)
		err[1] = CONNECTION_ERROR_STR;
	if (g_error_code == NONE_QUOTE_ERROR)
		err[1] = NONE_QUOTE_ERROR_STR;
	ft_printf(err[0], g_error_code, err[0], g_row, g_column + 1);
}


int main(int argc, char **argv)
{
	int	flag_mode;

	g_error_code = 0;
	g_column = 0;
	g_row = 0;
	if (argc >= 2)
	{
		flag_mode = 1;//check_flags(argv + 1, argc - 1, "-s");
		while (argc > 1)
			if ((g_error_code = cor_open_file(argv[--argc], flag_mode)))
				print_error();
	}
	else if (argc == 1)
		ft_printf("Usage: %s [-a] <sourcefile.s>\n", argv[0]);
	return (0);
}
