/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:04:03 by majjig            #+#    #+#             */
/*   Updated: 2021/11/19 01:33:15 by majjig           ###   ########.fr       */
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

/* MACROS */

# define BASE ((base == 'u') ? 10 : 16)

#endif
