/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_undertake.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:46:47 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/06 17:38:46 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define TCURRCYC	1350
#define TCURRDELTA	250


/*						Diverse input;
	size_t				lifereg[17] = { 900, 200, 500, 350, 200, 1300, 1299, \
										1250, 600, 1300, 100, 200, 1301, 1344, \
										1345, 1346, 199 };

						Invalid input;
	size_t				lifereg[17] = { 1, 3, 4, 5, 6, 7, 8, \
										9, 18, 11, 100, 200, 12, 13, \
										14, 15, 16 };
*/

int						main(void)
{
	t_world				nexus;
	size_t				lifereg[17] = { 1, 3, 4, 5, 6, 7, 8, \
										9, 18, 11, 100, 200, 12, 13, \
										14, 15, 16 };
	size_t				iterator[5] = { 4, 4, 1, 4, 4 };
	int					k = 0;
	t_dvasa				*dvas_ptr = NULL;
	t_dvasa				*next = NULL;
	
	t_vasa				*vas_ptr = NULL;

	ft_bzero(&nexus, sizeof(nexus));
	nexus.cyc.cycle = TCURRCYC;
	nexus.cyc.cycle_delta = TCURRDELTA;
	dvas_ptr = ft_create_leafnode_r(NULL, 0);
	next = dvas_ptr;
	for (int i = 0; i < 5; i++)
	{
		while(iterator[i])
		{
			ft_lstadd((t_list **)&vas_ptr, \
						(t_list *)ft_lstnew_r(ft_memalloc(sizeof(t_carry)), \
															sizeof(t_carry)));
			vas_ptr->gen.carry->last_live_op = lifereg[k++];
			iterator[i]--;
		}
		vas_ptr = (t_vasa *)ft_lstrot_rec((t_list *)vas_ptr, NULL);
		while(vas_ptr)
		{
			ft_add_offspring(next, vas_ptr);
			vas_ptr = vas_ptr->next;
		}
		ft_add_leafnode(&next, ft_create_leafnode_r(NULL, 0));
		next = next->right.du_vasa;
	}
		next = NULL;
		ft_tree_undertaker(&dvas_ptr, &next, &nexus.cyc);
		ft_destroy_leaftree(&dvas_ptr, &next);
}
