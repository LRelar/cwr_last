/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gen_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:27:56 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/22 22:13:17 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

typedef int				t_datacmp_rout(void *a, void *b);

typedef struct	s_mystruct
{
	char		*msg;
	uint8_t		status;
	long		id;
}				t_mystruct;

void			ft_fillshit(t_mystruct *struct_arr, int amount)
{
	int			i = 0;
	static char	*msges[6] = { "This is the first one\n", \
							"This is the second one\n", \
							"This is the third one\n", \
							"This is the fourth one\n", \
							"This is the last one.\n", \
							NULL};

	while (i < amount)
		{
			struct_arr[i].id = random();
			struct_arr[i].msg = msges[i];
			struct_arr[i].status = (uint8_t)struct_arr[i].id;
			i++;
		}
	struct_arr[4].id = 0;
}

void			ft_fill_arr(t_mystruct **ptr_arr, t_mystruct *struct_arr, \
																	int amount)
{
	int			i = 0;

	while (i < amount)
	{
		ptr_arr[i] = &struct_arr[i];
		i++;
	}
}
int				ft_sort_by_id(void *a, void *b)
{
	return ((int)((t_mystruct *)a)->id > (int)((t_mystruct *)b)->id);
}

int				main(void)
{
	t_mystruct	strarr[5];
	t_mystruct	**ptr_arr = (t_mystruct **)ft_memalloc((5 + 1)* sizeof(t_mystruct *));

	ft_bzero (&strarr[0], sizeof(strarr));
	ft_fillshit(&strarr[0], 5);
	ft_fill_arr(ptr_arr, &strarr[0], 5);
	ft_srt_bubble_genarr((void **)ptr_arr, 5, &ft_sort_by_id);
	return (0);
	

}