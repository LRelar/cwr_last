# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andru <andru@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 00:16:21 by mschimme          #+#    #+#              #
#    Updated: 2021/03/18 00:46:19 by andru            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
CFLAGS		:=	-Wall -Wextra -Werror -g
REMOVE		:=	/bin/rm -rf
CC			:=	clang

#**********************				PATHS:			***************************#
VPATH		:=	./src/errors: \
			./src/errors/ft_printf: \
			./src/gnl: \
			./src/lists: \
			./src/lists/lists_u: \
			./src/lists/lists_d: \
			./src/memory: \
			./src/numeric: \
			./src/output: \
			./src/output/ft_printf: \
			./src/output/ft_printf/floats: \
			./src/sfalia_func: \
			./src/string: \
			./src/cmp: \
			./src/sort:

#**********************				ERRORS:			***************************#
SOURCE	+=	malloc_err.c \
			var_overflow.c \
			broken_chain_err.c \
			mixed_input.c

#**********************				GNL:			***************************#
SOURCE	+=	get_next_line.c \
			gls_supp.c

#**********************				LISTS:			***************************#
SOURCE	+=	ft_del.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstnew_r.c \
			ft_lstrot_rec.c \
			ft_lstrot_arr.c

SOURCE	+=	ft_dlstadd.c \
			ft_dlstdel.c \
			ft_dlstdelone.c \
			ft_dlstnew.c \
			ft_dlstnew_r.c \
			ft_dlstwipe.c \
			ft_dlstwipe_ring.c

#**********************				MEMORY:			***************************#
SOURCE	+=	ft_bzero.c \
			ft_calloc.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c

#**********************				NUMERIC:		***************************#
SOURCE	+=	check_overflow.c \
			ft_strtonum.c

#**********************				OUTPUT:			***************************#
SOURCE	+=	ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c

#**********************				OUTPUT/PRINTF:	***************************#
SOURCE	+=	antoi.c \
			check_color.c \
			check_format_word.c \
			check_vari_cont_chain.c \
			flag_hash.c \
			flag_length.c \
			flag_minus.c \
			flag_plus.c \
			flag_precision.c \
			flag_space.c \
			flag_substring.c \
			flag_type.c \
			flag_width.c \
			flag_wildcard.c \
			flag_zero.c \
			ft_printf.c \
			ft_printf_fd.c \
			hex_default.c \
			hex_long.c \
			hex_long_long.c \
			hex_long_long_cap.c \
			hex_short.c \
			hex_short_short.c \
			int_default.c \
			int_long.c \
			int_long_long.c \
			int_long_long_cap.c \
			int_short.c \
			int_short_short.c \
			mem_default.c \
			mem_printer.c \
			oct_default.c \
			oct_long.c \
			oct_long_long.c \
			oct_long_long_cap.c \
			oct_short.c \
			oct_short_short.c \
			parse_format.c \
			prepare_va_list.c \
			ptr_default.c \
			scan_form_word.c \
			scan_string.c \
			skip_va_arg.c \
			string_default.c \
			type_char.c \
			type_default.c \
			type_dummy.c \
			type_float.c \
			type_hex.c \
			type_hex_cap.c \
			type_integer.c \
			type_mem.c \
			type_oct.c \
			type_ptr.c \
			type_string.c \
			type_unsigned.c \
			uns_default.c \
			uns_long.c \
			uns_long_long.c \
			uns_long_long_cap.c \
			uns_short.c \
			uns_short_short.c \
			width_left.c \
			width_right.c \
			wipe_structs.c \
			float_default.c \
			float_default_support_1.c \
			float_default_support_2.c \
			float_default_support_3.c \
			float_default_support_4.c \
			float_l_cap.c \
			intoa_float.c

#**********************				STRINGS:		***************************#
SOURCE	+=	ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_ctrldetect.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoal.c \
			ft_strcasecmp.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strchrcount.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnlen.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtolower.c \
			ft_strtoupper.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wdetect.c \
			ft_wstrlen.c \
			intoa.c \
			uintoa.c \
			uintoa_base.c

#**********************				CMP:			***************************#
SOURCE	+=	int_ptr_cmp.c \
			lst_cntsz_cmp.c

#**********************				SORT:			***************************#
SOURCE	+=	bubble_int_arr.c \
			bubble_list_arr.c \
			bubble_gen_arr.c

#**********************				sfalia_func:		***************************#

SOURCE	+=	ft_isspace.c \
			ft_strendwith.c\
			ft_charinstr.c\
			ft_atoix.c\
			ft_isspace.c\
			str_num_eq.c\
			ft_isdigit.c\
			ft_mod.c\
			ft_strreplace.c\
			ft_args.c\
			free_args.c\
			ft_strstrlst.c\
			ft_isnum.c\
			ft_atoil.c

#**********************				BODY:			***************************#

OBJ_DIR		:=	./obj
OBJECTS		:=	$(patsubst %,$(OBJ_DIR)/%,$(SOURCE:.c=.o))

.PHONY: all clean fclean re MAKEDIR

INC_DIR		:=	./includes
IFLAGS		+=	$(foreach d, $(INC_DIR), -I$d)

all: $(NAME)

$(NAME): MAKEDIR $(OBJECTS)
	@ar rc $@ $(OBJECTS)
	@echo ""
	@echo '$(NAME) ready'

MAKEDIR:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:%.c
	@echo -ne '\e[1K\e[0ECompile '
	@printf '\e[1;32m%-6s\e[m' $@
	@$(CC) $(CFLAGS) -o $@ $< -c $(IFLAGS)
	@echo -ne '\e[1K\e[0ECompile competed '

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
