/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwr_man.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:06:29 by mschimme          #+#    #+#             */
/*   Updated: 2020/12/26 14:01:55 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Macros working only in conjunction with mschimme, sfalia, 
*/
#ifndef CWR_MAN_H
# define CWR_MAN_H

#define WRN_HDR "WARNING!"
#define WRN_BDY "One ore more errors detected while parsing arguments!"
#define MAN_SYN "./corewar [-dump 100] [-n 50 ./champion.cor] [./champion2.cor]"
#define MAN_DESC_1 "Corewar takes arguments of the following type:\n\n"
#define MAN_DESC_2 "\t\033[1m-dump{eoc}\tPrint game state in hexdump style.\n"
#define MAN_DESC_3 "\t\tRequiires a positive integer of (int) size as a"
#define MAN_DESC_4 " parameter. Can be called more than 1 time.\n"
#define MAN_DESC_5 "\t\tThe battle will be interrupted after executing step of "
#define MAN_DESC_6 "a highest value in a given\n\t\tsequence of \"-dump\"s.\n"
#define MAN_DESC_7 "\t\033[1m-n{eoc}\tExplicitly assign ID to the"
#define MAN_DESC_8 " following Champion. If the number overflows (int) or is "
#define MAN_DESC_9 "of\n\t\tnegative value, or is not an interger, the ID of th"
#define MAN_DESC_10 "e folowing Champion will be assigned\n\t\tautomatically.\n"
#define MAN_DESC_11 "\n\tYou can add up to %d champions in the game.\n"
#define ERR_DESC_1 "{yellow}Errors pop up in stack-like way (latter go first)."
#define ERR_DESC_2 "Champion parsing related errors pop up in direct (queue)"
#define ERR_DESC_3 "order.\n\n"
#define WAR_CTRL_1 "A champ got control chars within its name! Ignore the case?"
#define WAR_CTRL_2 "A champ got control chars within its desc! Ignore the case?"
#define ERR_STAT_1 "The battle still can go on. Proceed?"
#define ERR_STAT_2 "Incorrect input. Waiting for: "
#define ERR_INPUT "Yes (Enter key) / No (Esc+Enter key)..."
#define ALIGN_MID(x) ((width - (int)x) / 2 + (int)x)

#define CONF_DESC_1 "The battle arena was configured with the following params:"

/*
**	Bogeys sizes.
*/

#define CONF_DESC_2 "\t\033[1mREG_SIZE{eoc}\tCurrent value: \""
#define CONF_DESC_3 "\". Supported values: winthin range of 1 .. 8 inclusive."
#define CONF_DESC_4 "\t\033[1mIND_SIZE{eoc}\tCurrent value: \""
#define CONF_DESC_5 "\". Supported values: winthin range of 1 .. 8 inclusive."
#define CONF_DESC_6 "\t\033[1mDIR_SIZE{eoc}\tCurrent value: \""
#define CONF_DESC_7 "\". Supported values: winthin range of 1 .. 8 inclusive."

#define CONF_DESC_8 "\t\033[1mMAX_PLAYERS{eoc}\tCurrent value: \""
#define CONF_DESC_9 "\". Consider champions size adjusting this one."
#define CONF_DESC_10 "\t\033[1mMEM_SIZE{eoc}\tCurrent value: \""
#define CONF_DESC_11 "\". ."


#endif