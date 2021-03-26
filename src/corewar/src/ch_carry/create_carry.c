/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_carry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 09:52:00 by mschimme          #+#    #+#             */
/*   Updated: 2021/03/26 20:59:47 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

t_carry			*ft_create_carry(void)
{
	static int	id;
	t_carry		*new_carry;

	if (!(new_carry = (t_carry *)ft_memalloc(sizeof(t_carry))))
		return (NULL);
	new_carry->id = ++id;
	return (new_carry);
}

/*
!Контракт:
	*	Функция не переносит каретку на предназначенное ей место.
	*	Функция не обновляет положение каретки!
	!	Функция не разрушает нексус в случае провала маллока!
	*	Функция обнуляет некоторые поля каретки (операнды, оп-код...).
	*	Копирование должно происходить ДО обновления параметров родителя (т.е.
		* родитель сперва выполняет свою операцию, а затем уже обновляет свой
		* exec_cyc и прочие параметры).
*/
t_carry			*ft_dupe_carry(t_carry *parent)
{
	t_carry		*offspring;
	int32_t		id;

	if (!(offspring = (t_carry *)ft_create_carry()))
		return (NULL);
	id = offspring->id;
	ft_memcpy((void *)offspring, (void *)parent, sizeof(t_carry));
	offspring->id = id;
	return (offspring);
}