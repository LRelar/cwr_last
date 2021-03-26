# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    t_compiler.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschimme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 13:29:58 by mschimme          #+#    #+#              #
#    Updated: 2020/12/26 11:25:23 by mschimme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

object=${1}
adds=${2}

gcc -Wall -Wextra -g -I./includes -I../libft/includes -I../../includes ./tests/$object.c $adds -L../libft -lft -g -o ./$object