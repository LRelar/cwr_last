/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_user.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:07:19 by mschimme          #+#    #+#             */
/*   Updated: 2020/12/26 17:29:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <cwr_man.h>

uint8_t		ft_ask_user(char *msg)
{
	char		buff[5];

	ft_printf_fd(2, "{yellow}WARNING!{eoc} %s\n%s\n", msg, ERR_INPUT);
	while (read(STDIN_FILENO, (void *)&buff[0], 4))
	{
		if (*(int *)&buff[0] == 0x0a1b || !ft_strcasecmp(&buff[0], "no\n"))
		{
			tcflush(STDIN_FILENO, TCIFLUSH);
			return (1);
		}
		else if (*(int *)&buff[0] == '\n' || !ft_strcasecmp(&buff[0], "yes\n"))
		{
			tcflush(STDIN_FILENO, TCIFLUSH);
			return (0);
		}
		else
		{
			tcflush(STDIN_FILENO, TCIFLUSH);
			ft_bzero(buff, sizeof(buff));
			ft_printf_fd(1, "%s %s\n", ERR_STAT_2, ERR_INPUT);
		}
	}
	return (1);
}
