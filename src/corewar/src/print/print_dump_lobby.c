/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dump_lobby.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:30:43 by mschimme          #+#    #+#             */
/*   Updated: 2021/03/24 22:15:15 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

# define LINE_SIZE 64 * 3

/*
**	Просто выводит состояние арены в текущий момент.
**	Принимает указатель на указатель головы t_vasa, которые в своем
**->gen.cyc_sol хранят циклы, в которые необхоимо дампнуться.
**	Через голову управляет цепочкой дампов.
**	Отпработав последний дамп-цикл должна подать сигнал на прерывание работы
**	цикла (возвратить 1).
*/

static inline void	set_dumpline(char str[LINE_SIZE], uint8_t **bytes, size_t *i,
																	size_t max)
{
	size_t	cpy;
	uint8_t	*bytes_cpy;
	uint8_t	tmp;
	char	*str_cpy;

	cpy = *i;
	str_cpy = str;
	bytes_cpy = *bytes;
	ft_bzero(str, sizeof(char) * (LINE_SIZE));
	while (cpy < max)
	{
		tmp = *bytes_cpy / 16;
		*str++ = tmp + (tmp > 9 ? 'a' - 10 : '0');
		tmp = *bytes_cpy++ % 16;
		*str++ = tmp + (tmp > 9 ? 'a' - 10 : '0');
		*str++ = ' ';
		if (!(++cpy % 0x40))
			break ;
	}
	str_cpy[LINE_SIZE - 1] = '\0';
	*bytes = bytes_cpy;
	*i = cpy;
}


/*
TODO: ACHTUNG!! КОСТЫЛЬ В СТИЛЕ ВОВЫ! ИСПРАВИТЬ НАХУЙ!
*/
uint8_t				ft_print_dump(t_world *nexus)
{
	t_vasa			*ptr;
	char			str[LINE_SIZE];
	uint8_t			*bytes;
	size_t			i;
	const size_t	max = MEM_SIZE;

	i = 0;
	ptr = nexus->cyc.cyc_to_dump;
	bytes = nexus->arena + sizeof(RTP);
	while (i < max)
	{
		ft_printf("0x%.4x : ", i);
		set_dumpline(str, &bytes, &i, max);
		ft_putstr(str);
		ft_putendl(" ");														//* Костылинг!
	}
	nexus->cyc.cyc_to_dump = nexus->cyc.cyc_to_dump->next;
	ptr->gen.cyc_sol = 0;
	free(ptr);
	return (nexus->cyc.cyc_to_dump == NULL);
}
