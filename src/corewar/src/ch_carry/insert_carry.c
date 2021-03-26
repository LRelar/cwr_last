/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_carry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 23:21:19 by mschimme          #+#    #+#             */
/*   Updated: 2020/10/31 15:47:20 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>


/*
*	ПРОВЕРИЛ.
TD:	Удалить / Оставить. Нигде не используется.
**	If t_dvasa is vacant (has no offsprings, ->left.gen.vasa == NULL), 
**	it inhabitates t_dvasa both in core (t_dvasa->gen.vasa) and its offspings
**	(t_dvasa->left.un_vasa);
**	If t_dvasa has offsprings, it's prolongs chain, adding new t_vasa to it's
**	tail.
// TD:	Убрать все случаи использования.
*/
void		ft_add_offspring_by_order(t_dvasa *leaf, t_vasa *new)
{
	if (leaf->left.un_vasa)
		leaf->left.un_vasa->next = new;
	else
	{
		leaf->gen.vasa = new;
		leaf->content_size = sizeof(t_vasa);
	}
	leaf->left.un_vasa = new;
	new->next = NULL;
}

static void	ft_insert_amid_chain(t_vasa *ptr, t_vasa *new)
{
	while (ptr->next)
	{
		if (new->gen.carry->id > ptr->next->gen.carry->id)
			break ;
		ptr = ptr->next;
	}
	new->next = ptr->next;
	ptr->next = new;
}

/*
*	ПРОВЕРИЛ.
!КОНТРАКТ:
	*	t_dvasa *leaf	- должен быть валидным, на входе не проверяется.
	*	t_vasa *new		- должен быть валидным, на входе не проверяется.
*/
void		ft_add_offspring_by_id(t_dvasa *leaf, t_vasa *new)
{
	t_vasa	*ptr;

	ptr = leaf->gen.vasa;
	if (leaf->left.un_vasa && new->gen.carry->id < \
											leaf->left.un_vasa->gen.carry->id)
	{
		new->next = leaf->left.un_vasa->next;
		leaf->left.un_vasa->next = new;
		leaf->left.un_vasa = new;
	}
	else if (ptr && new->gen.carry->id > ptr->gen.carry->id)
	{
		new->next = ptr;
		leaf->gen.vasa = new;
	}
	else if (ptr)
		ft_insert_amid_chain(ptr, new);
	else
	{
		leaf->gen.vasa = new;
		leaf->left.un_vasa = new;
		new->next = NULL;
		leaf->content_size = sizeof(t_vasa);
	}
}
