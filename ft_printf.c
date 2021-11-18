/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:49:22 by majjig            #+#    #+#             */
/*   Updated: 2021/11/18 04:19:34 by majjig           ###   ########.fr       */
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
				count += write(1, va_arg(ap, char *), 1);
			else if (s[i] == 's')
				ft_putstr(va_arg(ap, char *), &count);
			else if (s[i] == 'x' || s[i] == 'X' || s[i] == 'd' || s[i] == 'i')
				ft_putnbr(va_arg(ap, int), s[i], &count);
			else if (s[i] == 'p')
				ft_putnbr(va_arg(ap, int), 'x', &count);
			else if (s[i] == 'u')
				ft_putunsigned(va_arg(ap, unsigned int), &count);
			else if (s[i] == 'p')
				ft_putad(va_arg(ap, unsigned long), &count);
		}
		else
			count += write(1, s + i, 1);
	}
	return (count);
}
