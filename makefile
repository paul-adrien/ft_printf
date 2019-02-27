# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:54:18 by plaurent          #+#    #+#              #
#    Updated: 2019/02/26 15:10:01 by eviana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

CFLAGS = -Wall -Werror -Wextra

SRC = main.c ft_build_str.c ft_conv_di.c ft_conv_p.c ft_conv_s.c			\
	  ft_conv_c.c ft_dispatch.c ft_find.c ft_formattotab.c ft_printf.c		\
	  ft_print_asset.c ft_special.c ft_conv_oux.c ft_conv_percent.c			\
	  ft_noconv.c ft_conv_f.c ft_check_arg_nb.c

HEADER = ft_printf.h

LIBFT = libft/libft.a

OBJ = main.o ft_build_str.o ft_conv_di.o ft_conv_p.o ft_conv_s.o			\
	  ft_conv_c.o ft_dispatch.o ft_find.o ft_formattotab.o ft_printf.o		\
	  ft_print_asset.o ft_special.o ft_conv_oux.o ft_conv_percent.o			\
	  ft_noconv.o ft_conv_f.o ft_check_arg_nb.o

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT) -I $(HEADER)

.PHONY:clean

clean:
	/bin/rm -f $(OBJ) libft.a

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
