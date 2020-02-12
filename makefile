# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:54:18 by plaurent          #+#    #+#              #
#    Updated: 2019/03/19 14:48:31 by eviana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG = 0
CC = gcc
CFLAGS = -Wall -Werror -Wextra

ifeq ($(DEBUG),0)
	NAME = libftprintf.a
else
	NAME = printf
endif

RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
PURPLE = "\033[0;35m"
CYAN = "\033[0;36m"
MAGENTA = "\033[0;35;1m"
RESET = "\033[0m"

ifeq ($(DEBUG),0)
	SRC = $(wildcard libft/*.c)												\
		ft_build_str.c ft_conv_di.c ft_conv_p.c ft_conv_s.c					\
		ft_conv_c.c ft_dispatch.c ft_find.c ft_formattotab.c ft_printf.c	\
		ft_print_asset.c ft_special.c ft_conv_oux.c ft_conv_percent.c		\
		ft_conv_f.c ft_noconv.c ft_setprint.c ft_width.c ft_inf_f.c			\
		ft_preci_0_f.c ft_fill_buff.c ft_set_width.c
	HEADER = ft_printf.h libft/libft.h
else
	SRC = $(wildcard libft/*.c)													\
		main.c ft_build_str.c ft_conv_di.c ft_conv_p.c ft_conv_s.c				\
		ft_conv_c.c ft_dispatch.c ft_find.c ft_formattotab.c ft_printf.c		\
		ft_print_asset.c ft_special.c ft_conv_oux.c ft_conv_percent.c			\
		ft_noconv.c ft_conv_f.c ft_setprint.c ft_width.c ft_inf_f.c				\
		ft_preci_0_f.c ft_fill_buff.c ft_set_width.c
	HEADER = ft_printf.h
endif

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
ifeq ($(DEBUG),0)
		@echo $(CYAN)---Compilating with [$(GREEN)RELEASE$(CYAN)] mode---
		@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo $(CYAN)---------------$(GREEN)SUCCESS$(CYAN)---------------
else
		@echo $(CYAN)---Compilating with [$(YELLOW)DEBUG$(CYAN)] mode---
		@make -C libft
		@$(CC) -o $(NAME) $(CFLAGS) $(LIB) $(OBJ) -I $(HEADER)
		@echo $(CYAN)--------------$(GREEN)SUCCESS$(CYAN)--------------
endif

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ) $(wildcard *.o)
	@echo $(CYAN)---Objects have been cleaned---

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)
	@echo $(CYAN)---Exec has been cleaned---

re: fclean all
