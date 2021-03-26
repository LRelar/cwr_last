/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 21:58:36 by andru196          #+#    #+#             */
/*   Updated: 2020/08/20 00:22:39 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ERROR_H
# define COREWAR_ERROR_H

# define MALLOC_ERROR				-1
# define SOURCE_EXTENSION_ERROR 	100
# define OPEN_FILE_ERROR			22
# define LABEL_SIZE_ERROR			-8
# define LABEL_FORBIDDEN_CHAR		-80
# define COMMAND_NOT_FOUND			-404
# define ARGS_ERROR					-101
# define PROGRAM_SIZE_LIMIT			-800
# define CONNECTION_ERROR			-777
# define NONE_QUOTE_ERROR			-409
# define NONE_PROG_NAME_ERROR		-410
# define NONE_COMMENT_ERROR			-411
# define LONG_NAME_ERROR			-501
# define LONG_COMMENT_ERROR			-502
# define BAD_SYMBOL_ERROR			-666

# define MERR						MALLOC_ERROR
# define SEERR						SOURCE_EXTENSION_ERROR
# define OFERR						OPEN_FILE_ERROR
# define LSERR						LABEL_SIZE_ERROR
# define LFCERR						LABEL_FORBIDDEN_CHAR
# define CNFERR						COMMAND_NOT_FOUND
# define AERR						ARGS_ERROR
# define PSLERR						PROGRAM_SIZE_LIMIT
# define CERR						CONNECTION_ERROR
# define NQERR						NONE_QUOTE_ERROR
# define NPNERR						NONE_PROG_NAME_ERROR
# define NCERR						NONE_COMMENT_ERROR
# define LNERR						LONG_NAME_ERROR
# define LCERR						LONG_COMMENT_ERROR
# define BSERR						BAD_SYMBOL_ERROR

# define MALLOC_ERROR_STR			"Memory allocation failed"
# define SOURCE_EXTENSION_ERROR_STR	"Source file extension wrong"
# define OPEN_FILE_ERROR_STR		"Can't open file"
# define LABEL_SIZE_ERROR_STR		"Length of label is too big"
# define LABEL_FORBIDDEN_CHAR_STR	"Label contains forbidden character"
# define COMMAND_NOT_FOUND_STR		"Unknown command"
# define ARGS_ERROR_STR				"Error in arguments list"
# define PROGRAM_SIZE_LIMIT_STR		"Too big program"
# define CONNECTION_ERROR_STR		"Label not found"
# define NONE_QUOTE_STR     		"Quote not found"
# define NONE_PROG_NAME_STR			"Name of program not found"
# define NONE_COMMENT_STR			"Comment not found"
# define TOO_LONG_NAME_STR			"Name of program too long"
# define TOO_LONG_COMMENT_STR		"Comment of program too long"
# define BAD_SYMBOL_STR				"Non ASCII symbol"

#endif
