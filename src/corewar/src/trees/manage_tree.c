/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 21:45:02 by mschimme          #+#    #+#             */
/*   Updated: 2020/11/15 19:00:25 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	Purges dead carries (and their containers) and excludes leafnodes left with
**	no carries within them.
*/

#define DEATH_CYC cyc_ptr->cyc_to_die

static uint8_t	ft_carryhead_control(t_vasa **head)
{
	t_vasa				*carry_ptr;

	carry_ptr = *head;
	(*head) = (*head)->next;
	ft_lstdelone((t_list **)&carry_ptr, &ft_del);
	return (1);
}

/*
TD:	ПРОВЕРИТЬ В БОЕВОМ РЕЖИМЕ РАБОТОСПОСОБНОСТЬ без !(*head) проверки в 
	TD: первом if.
TD:	Проверить корректность поведения. Возможно нужно не '> cyc_ptr->cyc_to_die'
	TD: а '>= cyc_tr->cyc_to_die'.
!	На тесте требует проверку !(*head). Не имеет смысла (не должна иметь) в 
	! боевом применении, так как не должно быть такой конфигурации tree, при
	! которой leafnode->gen.vasa == NULL.
*	Последний if обновляет указатель на хвост очереди цикла
	* (leafnode->left.un_vasa) т.к. последний используется в текущей версии 
	* ft_add_offspring_by_ функций.
*/
inline static uint8_t	ft_carry_control(t_dvasa *leafnode, t_vasa **head, t_cycle *cyc_ptr)
{
	t_vasa				*carry_ptr;
	t_vasa				*subst;

	if (!(*head) || !((*head)->gen.carry))
		return (0);
	if (cyc_ptr->cycle - (*head)->gen.carry->last_live_op >= DEATH_CYC)
		return (ft_carryhead_control(head));
	carry_ptr = (*head)->next;
	subst = (*head);
	while (carry_ptr)
	{
		if (cyc_ptr->cycle - carry_ptr->gen.carry->last_live_op >= DEATH_CYC)
		{
			subst->next = carry_ptr->next;
			ft_lstdelone((t_list **)&carry_ptr, &ft_del);
			carry_ptr = subst->next;
			continue ;
		}
	carry_ptr = carry_ptr->next;
	subst = subst->next;
	}
	if (leafnode->left.un_vasa != subst)
		leafnode->left.un_vasa = subst;
	return (0);
}

inline static void		ft_leaf_control(t_dvasa *first, t_dvasa **vacant, \
															t_cycle *cyc_ptr)
{
	t_dvasa				*second;

	second = first->right.du_vasa;
	while (second)
	{
		if (ft_carry_control(second, &second->gen.vasa, cyc_ptr))
			continue ;
		if (!(second->gen.vasa))
		{
			second = second->right.du_vasa;
			if (!(vacant))
			{
				*vacant = first->right.du_vasa;
				ft_bzero(*vacant, sizeof(t_dvasa));
			}
			else
				free(first->right.du_vasa);
			first->right.du_vasa = second;
			continue ;
		}
		first = second;
		second = second->right.du_vasa;
	}
}

/*
*	ПРОВЕРИЛ.
!Контракт:
	*	Переданные t_dvasa должны проверяться на валидность.
	*	t_cycle *cyc_ptr должен относиться к t_world.
	*	Осуществляет полный контроль над деревом лифнод
		* (имеет право *tree = NULL)
	*	Осуществляет полный контроль над вакантной лифнодой.
	*	НЕ ДОЛЖНА оставлять пустые (не содержащие t_vasa в ->gen.vasa) лифноды.
	
**	'while' cycle is to update the head of the queue if it's being removed.
**	'if' part is to manage those leafnodes that are left empty: they're either
**	sent to 'vacant' ptr for later reuse, or being freed if we've vacant alrdy.
**	Also this function deals with the head of the tree (hence recursion).
**	Rest of the tree is processed in cycle manner thanks to ft_leaf_control.
**	Why this method: reduce recursive instances.
*/
void					ft_tree_undertaker(t_dvasa **tree, t_dvasa **vacant, \
															t_cycle *cyc_ptr)
{
	t_dvasa				*leaf_ptr;

	if (!(*tree))
		return ;
	leaf_ptr = *tree;
	while (ft_carry_control(leaf_ptr, &leaf_ptr->gen.vasa, cyc_ptr))
		;
	if (!(leaf_ptr->gen.vasa))
		{
			*tree = (*tree)->right.du_vasa;
			if (!(*vacant))
			{
				*vacant = leaf_ptr;
				ft_bzero(*vacant, sizeof(t_dvasa));
			}
			else
				free(leaf_ptr);
			ft_tree_undertaker(tree, vacant, cyc_ptr);
			return ;
		}
	ft_leaf_control(leaf_ptr, vacant, cyc_ptr);
}
