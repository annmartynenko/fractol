#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 14:49:21 by amartyne          #+#    #+#              #
#    Updated: 2018/04/11 16:19:47 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_memset.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_atoi.c ft_bzero.c \
ft_putstr.c ft_putchar.c ft_memcpy.c ft_memccpy.c ft_strncpy.c ft_strcmp.c \
ft_strncmp.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memmove.c ft_strlcat.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strtrim.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_itoa.c \
ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstdel.c ft_lstmap.c \
ft_swap.c ft_foreach.c ft_sqrt.c ft_range.c ft_power.c ft_arrfree.c \
ft_lstaddback.c get_next_line.c \
ft_printf/ft_printf.c ft_printf/number.c ft_printf/ft_itoa_base.c \
ft_printf/ft_putunsnbr.c ft_printf/extra_fun.c ft_printf/unicode.c \
ft_printf/find_flag.c ft_printf/for_flags.c ft_printf/if_flags.c \
ft_printf/ft_putstring.c ft_printf/ft_putnumber.c ft_printf/specifier.c \
ft_printf/if_flags_d.c ft_printf/ft_putchar.c \
ft_printf/ft_putstr.c \
ft_printf/ft_putnbr.c ft_printf/ft_putnbr.c ft_printf/if_flags_ito.c \
ft_printf/valid.c ft_printf/not_spec.c ft_printf/ft_itoa_base_int.c \
ft_printf/ft_itoa_unslong.c ft_printf/ft_itoa_max.c ft_printf/ft_putint.c \
ft_printf/for_add.c ft_printf/for_p.c

HDR = libft.h

OUT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	gcc $(FLAGS) -c $<

$(NAME): $(SRC)
	gcc $(FLAGS) -c $(SRC) -I $(HDR)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make