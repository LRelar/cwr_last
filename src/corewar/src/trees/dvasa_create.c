/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvasa_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:44:05 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 22:03:05 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
/*
*	ПРОВЕРИЛ.
*/
t_dvasa		*ft_create_leafnode_r(void const *content, size_t content_size)
{
	t_dvasa	*new;

	if (!(new = (t_dvasa *)ft_memalloc(sizeof(t_dvasa))))
		return ((void *)(size_t)ft_err_malloc("new", __func__) - 1);
	new->gen.content = (void *)content;
	if (content)
		new->content_size = content_size;
	return (new);
}

/*
TD:	Удалить / Оставить. Нигде не используется.
*/
t_dvasa		*ft_create_leafnode(void const *content, size_t content_size)
{
	t_dvasa	*new;

	if (!(new = (t_dvasa *)ft_memalloc(sizeof(t_dvasa))))
		return ((void *)(size_t)ft_err_malloc("new", __func__) - 1);
	if (content)
	{
		if (!(new->gen.content = (void *)ft_memalloc(content_size)))
		{
			free(new);
			return ((void *)(size_t)ft_err_malloc("content", __func__) \
																		- 1);
		}
		new->gen.content = ft_memcpy(new->gen.content, content, content_size);
		new->content_size = content_size;
	}
	return (new);
}