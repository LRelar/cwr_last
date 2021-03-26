# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschimme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 20:04:15 by mschimme          #+#    #+#              #
#    Updated: 2020/10/31 20:09:45 by mschimme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_LIB	=	./src/libft

.PHONY: all clean fclean re corewar asm

all: corewar asm

corewar:
		@make -f mker_cwr

asm:
		@make -f mker_asm

clean:
		@$(MAKE) -C $(DIR_LIB) clean
		@make -f mker_cwr clean
		@make -f mker_asm clean

fclean: clean
		@$(MAKE) -C $(DIR_LIB) fclean
		@make -f mker_cwr fclean
		@make -f mker_asm fclean

re: fclean all