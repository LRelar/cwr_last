/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gnl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:13:39 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 23:49:32 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	g_gnl_read;

int			main(int argc, char** argv)
{
	char	*src;
	int		fd = 0;
	char	*ptr = NULL;
	int		gnl_res = 0;
	int		print_res = 0;

	if (argc < 2)
		return (0);
	src = argv[1];
	if ((fd = open(src, O_RDONLY)) == -1)
		return (0);
	while ((gnl_res = get_next_line(fd, &ptr)))
	{
		DEBintt(gnl_res)
		DEBintt(g_gnl_read) DEBend()
		print_res = ft_strlen(ptr);
		DEBend()
		DEBintt(print_res) DEBend()
		free(ptr);
		ptr = NULL;
		if (g_gnl_read != print_res)
			return (1);
	}
	close(fd);
	return (0);
}

