/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:49:22 by majjig            #+#    #+#             */
/*   Updated: 2021/11/18 23:35:17 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = -1;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (s[++i] == 'c')
				ft_putchar(va_arg(ap, int), &count);
			else if (s[i] == 's')
				ft_putstr(va_arg(ap, char *), &count);
			else if (s[i] == 'i' || s[i] == 'd')
				ft_putnbr(va_arg(ap, int), &count);
			else if (s[i] == 'u' || s[i] == 'X' || s[i] == 'x')
				ft_putunsigned(va_arg(ap, unsigned int), s[i], &count);
			else if (s[i] == 'p')
				ft_putad(va_arg(ap, unsigned long int), &count);
			else
				count += write(1, s + i, 1);
		}
		else
				count += write(1, s + i, 1);
	}
	return (va_end(ap), count);
}
