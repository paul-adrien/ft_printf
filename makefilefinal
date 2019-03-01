# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:54:18 by plaurent          #+#    #+#              #
#    Updated: 2019/03/01 12:07:32 by eviana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC1 = ft_build_str.c ft_conv_di.c ft_conv_p.c ft_conv_s.c				\
	  ft_conv_c.c ft_dispatch.c ft_find.c ft_formattotab.c ft_printf.c	\
	  ft_print_asset.c ft_special.c ft_conv_oux.c ft_conv_percent.c		\
	  ft_conv_f.c ft_noconv.c ft_setprint.c ft_width.c

SRC2 = libft/ft_putchar_fd.c libft/ft_putnbr.c libft/ft_putendl.c libft/ft_putstr.c libft/ft_putchar.c	\
	  libft/ft_itoa.c libft/ft_strsplit.c libft/ft_strtrim.c libft/ft_strjoin.c libft/ft_strsub.c		\
	  libft/ft_strnequ.c libft/ft_strequ.c libft/ft_strmapi.c libft/ft_strmap.c libft/ft_striteri.c		\
	  libft/ft_striter.c libft/ft_strclr.c libft/ft_strdel.c libft/ft_strnew.c libft/ft_memdel.c		\
	  libft/ft_memalloc.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_isprint.c libft/ft_isascii.c	\
	  libft/ft_isalnum.c libft/ft_isdigit.c libft/ft_isalpha.c libft/ft_atoi.c libft/ft_strncmp.c		\
	  libft/ft_strcmp.c libft/ft_strnstr.c libft/ft_strstr.c libft/ft_strrchr.c libft/ft_strlcat.c		\
	  libft/ft_strchr.c libft/ft_strncat.c libft/ft_strcat.c libft/ft_strncpy.c libft/ft_strcpy.c		\
	  libft/ft_memcmp.c libft/ft_memchr.c libft/ft_memmove.c libft/ft_memccpy.c libft/ft_memcpy.c		\
	  libft/ft_bzero.c libft/ft_strlen.c libft/ft_memset.c libft/ft_putnbr_fd.c libft/ft_putendl_fd.c	\
	  libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_ltoa.c libft/ft_lltoa.c libft/ft_strrev.c 		\
	  libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c libft/ft_lstiter.c		\
	  libft/ft_lstmap.c libft/ft_foreach.c libft/ft_factorial.c	libft/ft_strcount.c						\
	  libft/ft_power.c libft/ft_fibonacci.c libft/ft_sqrt.c libft/ft_is_prime.c							\
	  libft/ft_utoa.c libft/ft_ultoa.c libft/ft_ulltoa.c libft/ft_convert_base.c libft/ft_putull.c		\

SRC3 = $(SRC1) $(SRC2)

HEADER = ft_printf.h libft/libft.h

OBJ1 = ft_build_str.o ft_conv_di.o ft_conv_p.o ft_conv_s.o				\
	  ft_conv_c.o ft_dispatch.o ft_find.o ft_formattotab.o ft_printf.o	\
	  ft_print_asset.o ft_special.o ft_conv_oux.o ft_conv_percent.o		\
	  ft_conv_f.o ft_noconv.o ft_setprint.o ft_width.o

OBJ2 = ft_putchar_fd.o ft_putnbr.o ft_putendl.o ft_putstr.o ft_putchar.o\
	  ft_itoa.o ft_strsplit.o ft_strtrim.o ft_strjoin.o ft_strsub.o		\
	  ft_strnequ.o ft_strequ.o ft_strmapi.o ft_strmap.o ft_striteri.o	\
	  ft_striter.o ft_strclr.o ft_strdel.o ft_strnew.o ft_memdel.o		\
	  ft_memalloc.o ft_tolower.o ft_toupper.o ft_isprint.o ft_isascii.o	\
	  ft_isalnum.o ft_isdigit.o ft_isalpha.o ft_atoi.o ft_strncmp.o		\
	  ft_strcmp.o ft_strnstr.o ft_strstr.o ft_strrchr.o ft_strlcat.o	\
	  ft_strchr.o ft_strncat.o ft_strcat.o ft_strncpy.o ft_strcpy.o		\
	  ft_memcmp.o ft_memchr.o ft_memmove.o ft_memccpy.o ft_memcpy.o		\
	  ft_bzero.o ft_strlen.o ft_memset.o ft_putnbr_fd.o ft_putendl_fd.o	\
	  ft_putstr_fd.o ft_strdup.o ft_ltoa.o ft_lltoa.o ft_strrev.o		\
	  ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o	\
	  ft_lstmap.o ft_foreach.o ft_factorial.o	ft_strcount.o			\
	  ft_power.o ft_fibonacci.o ft_sqrt.o ft_is_prime.o					\
	  ft_utoa.o ft_ultoa.o ft_ulltoa.o ft_convert_base.o ft_putull.o	\

OBJ3 = $(OBJ1) $(OBJ2)

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -c $(SRC3) -I $(HEADER)
	ar rc $(NAME) $(OBJ3)
	ranlib $(NAME)

.PHONY:clean

clean:
	/bin/rm -f $(OBJ3)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
