/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:57:29 by majjig            #+#    #+#             */
/*   Updated: 2021/11/24 20:02:55 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_detect(char flag, va_list ap, int *count)
{
	if (flag == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (flag == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (flag == 'i' || flag == 'd')
		ft_putnbr(va_arg(ap, int), count);
	else if (flag == 'u' || flag == 'X' || flag == 'x')
		ft_putunsigned(va_arg(ap, unsigned int), flag, count);
	else if (flag == 'p')
		ft_putad(va_arg(ap, unsigned long int), count);
	else
		*count += write(1, &flag, 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = -1;
	if (s == NULL)
		return (-1);
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
			ft_format_detect(s[++i], ap, &count);
		else
			count += write(1, s + i, 1);
	}
	return (va_end(ap), count);
}
