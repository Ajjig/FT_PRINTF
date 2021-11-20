/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:49:22 by majjig            #+#    #+#             */
/*   Updated: 2021/11/20 05:39:55 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (!c)
		return ((char *) s);
	return (0);
}

int	ft_space_flag(va_list ap, const char *s, int *count)
{
	int		i;
	int		nb;
	char	*str;

	i = 0;
	nb = 0;
	while (ft_strchr("ids", s[++i]) == 0)
	{
		nb += s[i] - 48 + (nb * 10);
		if (s[i] > '9' || s[i] < '0')
			return (0);
	}
	if (s[i] == 's')
	{
		str = va_arg(ap, char *);
		nb -= ft_strlen(str);
		while (nb-- > 0)
			*count += write(1, " ", 1);
		return (ft_putstr(str, count), i);
	}
	nb = va_arg(ap, int);
	if (nb >= 0)
		*count += write(1, " ", 1);
	return (ft_putnbr(nb, count), i);
}

int	ft_bonus_detect(const char *flag, va_list ap, int *count)
{
	int				nb;
	unsigned int	unb;

	if ((*flag == '+' || *flag == ' ') && ft_strchr("id", flag[1]))
	{
		nb = va_arg(ap, int);
		if (nb >= 0)
			*count += write(1, flag, 1);
		ft_putnbr(nb, count);
	}
	if (*flag == '#')
	{
		unb = va_arg(ap, unsigned int);
		if (flag[1] == 'x' && unb != 0)
			*count += write(1, "0x", 2);
		if (flag[1] == 'X' && unb != 0)
			*count += write(1, "0X", 2);
		ft_putunsigned(unb, flag[1], count);
	}
	return (0);
}

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
		{
			if (ft_strchr("#+", s[++i]) && (ft_strchr("idxX", s[i + 1])))
				ft_bonus_detect(&s[i++], ap, &count);
			if (s[i] == ' ')
				i += ft_space_flag(ap, &s[i], &count);
			else
				ft_format_detect(s[i], ap, &count);
		}
		else
			count += write(1, s + i, 1);
	}
	return (va_end(ap), count);
}
