# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majjig <majjig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 17:30:09 by majjig            #+#    #+#              #
#    Updated: 2021/11/22 02:01:01 by majjig           ###   ########.fr        #
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
	ft_putchar.c \
	ft_strlen.c

BNS = ft_printf_bonus.c \
	ft_putnbr.c \
	ft_putad.c \
	ft_putstr.c \
	ft_putunsigned.c \
	ft_putchar.c \
	ft_strlen.c \
	ft_intlen.c

to-rm-files = ft_printf.o
to-rm-bonus = ft_printf_bonus.o ft_intlen.o

INC = ft_printf.h

OBJS = ${SRCS:.c=.o}

OBJBNS = ${BNS:.c=.o}

all: $(NAME)

$(NAME): rm-bonus $(OBJS) $(INC)
	@$(CC) $(CFLAGS) $(SRCS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(OBJBNS)

fclean: clean
	@rm -f $(NAME)

rm-bonus:
	-@ar dv $(to-rm-bonus)

re: fclean all

re-bonus: fclean bonus

bonus: bnslib

bnslib: rm-mandatory $(OBJBNS) $(INC)
	@$(CC) $(CFLAGS) $(BNS)
	@ar rc $(NAME) $(OBJBNS)

rm-mandatory:
	-@ar dv $(NAME) $(to-rm-files)

.PHONY: bonus all clean fclean re re-bonus
