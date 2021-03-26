/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_itoal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 23:35:03 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/15 00:52:48 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int			main(void)
{
	long long	k;
	int			fd;
	char		*std = NULL;
	char		*ctm = NULL;

	asprintf(&std, "%lld", INT64_MAX);
	ctm = ft_itoal(INT64_MAX);
	if (!std || !ctm)
		return (5);
	if (strcmp(std, ctm))
		return (1);
	free(std);
	free(ctm);
	ctm = std = NULL;

	asprintf(&std, "%lld", INT64_MIN);
	ctm = ft_itoal(INT64_MIN);
	if (!std || !ctm)
		return (5);
	if (strcmp(std, ctm))
		return (2);

	asprintf(&std, "%lld", 0);
	ctm = ft_itoal(0);
	if (!std || !ctm)
		return (5);
	if (strcmp(std, ctm))
		return (10);


	fd = open("/dev/random", O_RDONLY);
	for (int i = 0; i < 500; i++)
	{
		free(std);
		free(ctm);
		ctm = std = NULL;
		read(fd, &k, 8);
		if ((-1 == asprintf(&std, "%lld", k)) || !(ctm = ft_itoal(k)))
			return (3);
		if (strcmp(std, ctm))
		{
			printf("ERROR!\nSTD: %s\n", std);
			printf("CTM: %s\n", ctm);
			break ;
		}
	}
	free(std);
	free(ctm);
	close(fd);

	
	return (0);
}