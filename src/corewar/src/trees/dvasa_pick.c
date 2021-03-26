/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvasa_pick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:11:06 by mschimme          #+#    #+#             */
/*   Updated: 2021/02/26 22:16:17 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
*	ПРОВЕРИЛ. Не проверял модуль обработки ошибки маллока (стандартный).
!Контракт:
	*	t_dvasa *tree должна быть не NULL.
	*	Может добавлять новые leafnode.
	*	Полный контроль над t_dvasa **new_node. Предполагается, что перед 
		* созданием новой leafnode, будет утилизрована пустая в *new_node.
	*	t_vasa *carry_bogey должна хранить каретку с актуальными значениями, в
		* т.ч. значениями exec_cyc.
*/
static void		ft_new_leafnode_insert(t_dvasa **tree, \
											t_dvasa **new_node, t_dvasa *root)
{
	t_dvasa		*bogey;

	if (*new_node)
	{
		ft_add_leafnode(tree, *new_node);
		*new_node = NULL;
	}
	else
	{
		bogey = (*tree);
		ft_add_leafnode(tree, ft_create_leafnode_r(NULL, 0));
		if (bogey == *tree)
		{
			ft_err_malloc("new_leafnode", __func__);
			ft_destroy_leaftree(&root, new_node);
			ft_manage_world(NULL);
		}
	}
}

/*
*	ПРОВЕРИЛ.
*	'if (!(tree->gen.vasa) ||...' - Во исполнение условий контракта
	* ft_carry_process, случаи, когда отрабатывается последняя каретка цикла, и
	* эта каретка будет единственной на исполнение в следующей лифноде,
	* текущая (уже пустая) лифнода не реутилизируется.
!	ПОЙМАЕТ СЕГУ, если в процессе поиска по цепочке лифнод найдет хотя бы одну
	! пустую (без gen.vasa) лифноду. Такого не должно быть: В процессе поиска
	! пустой может быть только ПЕРВАЯ (корневая, головная) лифнода.
	? При каких обстоятельствах могут возникнуть пустые лифноды? Если не была
	? исключена из цепочке лифнода, которая осталась без кареток после проверки
	? на cycle_to_die.
*/
void			ft_leafnode_pick(t_vasa *carry_cont, t_dvasa *tree, \
								t_dvasa **new_node, t_carry_cont_rout *manager)
{
	size_t		cyc_num;
	t_dvasa		*root;

	root = tree;
	cyc_num = carry_cont->gen.carry->exec_cyc;
	carry_cont->next = NULL;
	while(tree->right.du_vasa && \
				tree->right.du_vasa->gen.vasa->gen.carry->exec_cyc <= cyc_num)
		tree = tree->right.du_vasa;
	if (!(tree->gen.vasa) || tree->gen.vasa->gen.carry->exec_cyc != cyc_num)
		ft_new_leafnode_insert(&tree, new_node, root);
	manager(tree, carry_cont);
}

