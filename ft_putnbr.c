/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:34:59 by majjig            #+#    #+#             */
/*   Updated: 2021/11/18 21:18:44 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_putnbr(int nb, char base, int *count)
{
	if (nb < 0)
	{
		*count += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= BASE)
		ft_putnbr(nb / BASE, base, count);
	if (base == 'x')
		*count += write(1, &"0123456789abcdef"[nb % 16], 1);
	else if (base == 'X')
		*count += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	else if (base == 'd')
		*count += write(1, &"0123456789"[nb % 10], 1);
}
