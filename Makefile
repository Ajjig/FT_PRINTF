# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majjig <majjig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 17:30:09 by majjig            #+#    #+#              #
#    Updated: 2021/11/18 23:09:01 by majjig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wextra -Werror -Wall

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_putnbr.c \
	ft_putad.c \
	ft_putstr.c \
	ft_putunsigned.c \
	ft_putchar.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
