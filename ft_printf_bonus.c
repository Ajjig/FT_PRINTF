/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:49:22 by majjig            #+#    #+#             */
/*   Updated: 2021/11/24 20:23:57 by majjig           ###   ########.fr       */
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
	int		j;

	i = 0;
	nb = 0;
	while (ft_strchr("ids", s[++i]) == 0)
		nb = s[i] - 48 + (nb * 10);
	if (s[i] == STRING)
	{
		str = va_arg(ap, char *);
		nb -= ft_strlen(str);
		while (nb-- > 0)
			*count += write(1, " ", 1);
		return (ft_putstr(str, count), i);
	}
	j = va_arg(ap, int);
	nb -= ft_intlen(j) + 1;
	while (nb-- > 0)
		*count += write(1, " ", 1);
	if (j >= 0)
		*count += write(1, s, 1);
	return (ft_putnbr(j, count), i);
}

void	ft_bonus_detect(const char *flag, va_list ap, int *count)
{
	int				nb;
	unsigned int	unb;

	if ((*flag == PLUS) && ft_strchr("id", flag[1]))
	{
		nb = va_arg(ap, int);
		if (nb >= 0)
			*count += write(1, flag, 1);
		ft_putnbr(nb, count);
	}
	if (*flag == SHARP)
	{
		unb = va_arg(ap, unsigned int);
		if (flag[1] == HEXALOWER && unb != 0)
			*count += write(1, "0x", 2);
		if (flag[1] == HEXAUPPER && unb != 0)
			*count += write(1, "0X", 2);
		ft_putunsigned(unb, flag[1], count);
	}
}

void	ft_format_detect(char flag, va_list ap, int *count)
{
	if (flag == CHAR)
		ft_putchar(va_arg(ap, int), count);
	else if (flag == STRING)
		ft_putstr(va_arg(ap, char *), count);
	else if (flag == INTEGER || flag == DECIMAL)
		ft_putnbr(va_arg(ap, int), count);
	else if (flag == UNSIGNED || flag == HEXAUPPER || flag == HEXALOWER)
		ft_putunsigned(va_arg(ap, unsigned int), flag, count);
	else if (flag == ADDRESS)
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
		return (EXIT_ERROR);
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == PERCENT)
		{
			if (s[++i] == SHARP && (ft_strchr("xX", s[i + 1])))
				ft_bonus_detect(&s[i++], ap, &count);
			else if (s[i] == SPACE || s[i] == PLUS)
				i += ft_space_flag(ap, &s[i], &count);
			else
				ft_format_detect(s[i], ap, &count);
		}
		else
			count += write(1, s + i, 1);
	}
	return (va_end(ap), count);
}
