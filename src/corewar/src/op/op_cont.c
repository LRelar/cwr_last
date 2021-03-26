/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cont.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:30:47 by mschimme          #+#    #+#             */
/*   Updated: 2020/11/04 11:21:26 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr_op_defs.h>

/*
**!КОНТРАКТ:
**	*	Всегда принимает только валидный offset. Потому проверка не нужна.
**	*	Возвращает указатель
*/

const t_mop		*ft_get_op_cont(uint8_t offset)
{
	return (&stat_opset[offset]);
}

/*
**!КОНТРАКТ:
**	*	Всегда принимает только валидный offset. Проверка не предусмотрена.
**	*	Всегда принимает ptr, указывающий на инициализированную структуру.
**		* Предполагается, что структура выделяется на стеке.
*/

void			ft_clone_op_cont(uint8_t offset, t_mop *ptr)
{
	ft_memcpy(ptr, (const void *)&stat_opset[offset], sizeof(t_mop));
}

/*
**				old CYCLIC method to read operand types from coding byte:
**	#ifndef OPS_SHIFT
**	#define	OPS_SHIFT (4 - (i + 1))
**	#endif
**				WITHIN FUNCTION BLOCK:
**		uint8_t		i;
**		i = UINT8_MAX;
**		while (++i < ops_cont->ops_amount)
**			ops_cont->ops_types[i] &= code_byte & 3 << OPS_SHIFT >> OPS_SHIFT;
*/

/*
**!КОНТРАКТ:
**	*	uint8_t *arena	- всегда - адрес нулевого элемента массива арены
**		* (&nexus->arena[0 + sizeof(RTP)]);
**	*	intptr_t ptr	- значение carry->pos, которое всегда указывает на
**		* оп-код инструкции, подлежащей исполнению.
**	*	t_mop *ops_cont	- указатель на копию валидной t_mop структуры,
**		* соответствующей считанному оп-коду.
**	*	Выполняет проверку корректности поданного кодирующего байта на предмет
**		* соответствия его допустимым (в соответствии с инструкцией) значениям.
**	*	Определяет и сохраняет данные о конфигурации конкретного экземпляра
**		* инструкции.
**	*	Вычисляет размеры конкретного экземпляра инструкции.
**	*	Проверяет валидность выбранного регистра.
**	*	При успешной эвалуации возвращает 0, выявив ошибку, возвращает 1.
**	TODO:
**	/////TD:	Переделать. Исключить необходимость в ft_eval_operands_length.
**	/////TD:	Добавить параметром индекс контейнера инструкции.
**	/////TD:	В цликле через & сравнивать полученный тип опернды с допустимым.
**	/////	TD: Если не допустим, взводить флаг, записывать длину полученного.
**	/////TD:	перепроверить, лол епта!
**
**	Tester:		t_eval_operands.c
*/

uint8_t			ft_eval_operands_type(uint8_t *arena, intptr_t ptr, \
										t_mop *ops_cont, const t_mop *const ref)
{
	uint8_t		code_byte;
	uint8_t		flag;
	uint32_t	i;
	intptr_t	offset;

	flag = 0;
	code_byte = arena[ft_calc_addr(ptr + (intptr_t)OPC_SIZE)];
	ops_cont->ops_types[0] = stat_code_to_type[((code_byte & 0xC0) >> 6)];
	ops_cont->ops_types[1] = stat_code_to_type[((code_byte & 0x30) >> 4)];
	ops_cont->ops_types[2] = stat_code_to_type[((code_byte & 0x0C) >> 2)];
	ops_cont->ops_types[3] = stat_code_to_type[((code_byte & 0x03))];
	i = UINT32_MAX;
	offset = OPC_SIZE + OPCB_SIZE;
	while (++i < ops_cont->ops_amount)
	{
		flag |= !(ops_cont->ops_types[i] & ref->ops_types[i]);
		if (ops_cont->ops_types[i] == T_REG)
			flag |= !(ft_check_reg_is_valid(arena, ptr + offset));
		ops_cont->ops_length[i] = ft_step_size(ops_cont->ops_types[i], \
														ops_cont->t_dir_size);
		offset += ops_cont->ops_length[i];
	}
	ops_cont->length = offset;
	return (flag);
}

/*
**	!КОНТРАКТ:
**	*	arena	- всегда логическая арена.
**	*	pos 	- всегда указывает на "голову" инструкции на арене.
**	*	op_cont	- всегда "клон" op-структуры с уже высчитаными типами операнд.
**	!	не подлежит применению в инструкции без кодирующего байта:
**		! aff!
**		! live!
**		! zjmp!
**		! fork!
**		! lfork!
**
**	void	ft_eval_operands_length(uint8_t *arena, intptr_t pos, t_mop *op_cont)
**	{
**		uint8_t	i;
**		uint8_t	code_byte;
**
**		i = INT8_MAX;
**		code_byte = arena[ft_calc_addr(pos + (intptr_t)OPC_SIZE)];
**		while (++i < op_cont->ops_amount)
**		{
**			if (!op_cont->ops_types[i])
**			{
**				op_cont->ops_types[i] = stat_code_to_type[(code_byte & \
**											(3 << (6 - i * 2)) >> (6 - i * 2))];
**				op_cont->ops_length[i] = ft_step_size(op_cont->ops_types[i], \
**														op_cont->t_dir_size);
**			}
**		}
**		op_cont->length = OPC_SIZE + OPCB_SIZE + op_cont->ops_length[0] + \
**							op_cont->ops_length[1] + op_cont->ops_length[2] +
**							op_cont->ops_length[3];
**	}
*/
