/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:38:48 by mschimme          #+#    #+#             */
/*   Updated: 2020/11/15 18:54:29 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define STR_SGSTN "Correct the value in op.h and recompile."

/*
**	We allocate common memory space for name and description fields of the
**	champion entry. Less mallocs - easy memory management.
**	We always allocate memory for all those vacant champion entries.
**	So, if we've failed to allocate for all of them, we'll return 1 in
**	return check.
*/

inline static uint8_t	ft_init_champs_r(t_world *nexus)
{
	int					i;

	i = 0;
	while ((i != MAX_PLAYERS) && \
			(nexus->champ[i].name = (char *)ft_memalloc(PROG_NAME_LENGTH + \
										COMMENT_LENGTH + (REG_SIZE + 1) * 2)))
	{
		nexus->champ[i].desc = nexus->champ[i].name + \
			(uintptr_t)(PROG_NAME_LENGTH + REG_SIZE + 1);
		i++;
	}
	if (i != MAX_PLAYERS)
		ft_prox_err_malloc("CH_NAME", __func__);
	nexus->cyc.cyc_to_die = CYCLE_TO_DIE;
	nexus->cyc.next_check = CYCLE_TO_DIE;
	return (0);
}

/*
**	We don't use ft_init_champs_r return status as we either exit with malloc
**	error, or continue the run.
**!	cyc_to_die выставлен в CYCLE_TO_DIE, т.к. нулевой цикл - тоже цикл.
*/

inline static void		ft_init_world(t_world *nexus)
{
	ft_bzero(nexus, sizeof(t_world));
	ft_manage_world(nexus);
	nexus->cyc.cyc_to_die = (size_t)CYCLE_TO_DIE - 1ULL;
	ft_init_champs_r(nexus);
}

#ifdef NOMINAL_LAUNCH

int						main(int argc, char **argv)
{
	t_world				nexus;

	ft_init_world(&nexus);
	nexus.progname = *argv;
	argv++;
	if (argc > 1)
	{
		ft_read_params(&argv, &nexus);
		ft_prep_battle(&nexus);
		ft_exec_battle(&nexus);
	}
	else
		ft_show_man();
	ft_manage_world(NULL);
	return (0);
}

#endif

#ifdef FAULT_LAUNCH

int						main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_show_compconf();
	return (0);
}

#endif
