# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majjig <majjig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 17:30:09 by majjig            #+#    #+#              #
#    Updated: 2021/11/18 01:42:57 by majjig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wextra -Werror -Wall

NAME = ft_printf

SRCS = ft_printf.c \
	ft_putnbr.c \
	ft_putchar.c \
	ft_putstr.c \

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
clean:
	rm -rf *.o
