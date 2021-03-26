/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_battle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:16:19 by mschimme          #+#    #+#             */
/*   Updated: 2020/12/26 15:29:12 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <cwr_intro.h>

/*
TD:	Проверить в боевом режиме.
*/

inline static t_list	**ft_build_buff_nt(t_list **head, size_t size)
{
	t_list				**arr_ptr;
	size_t				i;
	t_list				*bogey;

	bogey = *head;
	i = 0;
	arr_ptr = (t_list **)ft_memalloc((size + 1) * sizeof(t_list *));
	while (i != size)
	{
		arr_ptr[i++] = bogey;
		bogey = bogey->next;
	}
	return (arr_ptr);
}

/*
**	ПРОВЕРИЛ.	t_arr_sort.c
*/

inline static void		ft_sort_dumps(t_list **head, size_t amount)
{
	t_list				**arr_ptr;

	if (!(arr_ptr = ft_build_buff_nt(head, amount)))
		ft_prox_err_malloc("arr_ptr", "ft_build_buff");
	ft_srt_listarr_bubble(head, arr_ptr, amount, ft_cyc_left_grt_right);
	free(arr_ptr);
}

/*
TD:	Проверить в боевом режиме.
TD:	Перепроверить на тесте, т.к. изменен nexus->arena!
*/

inline static void		ft_place_champs(t_world *nexus)
{
	uintptr_t			entry_ptr;
	int					step;
	int					ch_amount;
	uint8_t				*arena;

	arena = &nexus->arena[sizeof(RTP)];
	ch_amount = -1;
	step = MEM_SIZE / nexus->champs;
	entry_ptr = 0;
	while (++ch_amount != nexus->champs)
	{
		ft_memcpy((void *)(arena + entry_ptr), \
					(void *)nexus->champ_ord[ch_amount]->body, \
					(size_t)nexus->champ_ord[ch_amount]->size);
		entry_ptr += step;
	}
}

inline static void		ft_print_intro(t_champ **champ_arr)
{
	ft_printf(CWR_INTRO_MSG);
	while (*champ_arr)
	{
		ft_printf(CWR_CHAMP_DEC, (*champ_arr)->id, (*champ_arr)->size, \
								(*champ_arr)->name, (*champ_arr)->desc);
		champ_arr++;
	}
}

/*
TD:	Проверить в боевом режиме.
*/

void					ft_prep_battle(t_world *nexus)
{
	if (nexus->cyc.cyc_to_dump)
		ft_sort_dumps((t_list **)&nexus->cyc.cyc_to_dump, \
										nexus->cyc.cyc_to_dump->content_size);
	nexus->champ_ord = ft_build_champarr_sorted(&nexus->champ[0], nexus->champs);
	nexus->survivor = nexus->champ_ord[nexus->champs - 1];
	ft_place_champs(nexus);
	ft_print_intro(nexus->champ_ord);
	ft_init_carries(nexus);
}
