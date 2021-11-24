/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:04:03 by majjig            #+#    #+#             */
/*   Updated: 2021/11/24 20:26:23 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* INCLUDES */

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

/* PROTOTYPES */

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putunsigned(unsigned int nb, char base, int *count);
void	ft_putad(unsigned long int nb, int *count);
void	ft_putchar(char c, int *count);
int		ft_strlen(char *str);
int		ft_intlen(int nb);

/* MACROS */

# define BASE ((base == 'u') ? 10 : 16)
# define SPACE ' '
# define PLUS '+'
# define STRING 's'
# define CHAR 'c'
# define UNSIGNED 'u'
# define ADDRESS 'p'
# define HEXALOWER 'x'
# define HEXAUPPER 'X'
# define DECIMAL 'd'
# define INTEGER 'i'
# define PERCENT '%'
# define SHARP '#'
# define EXIT_ERROR -1
# define STR_HEXA_LOWER "0123456789abcdef"
# define STR_HEXA_UPPER "0123456789ABCDEF"
# define STR_DECIMAL "0123456789"

#endif
