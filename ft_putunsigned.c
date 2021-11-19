/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:27:07 by majjig            #+#    #+#             */
/*   Updated: 2021/11/19 01:29:11 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int nb, char base, int *count)
{
	if (nb >= BASE)
		ft_putunsigned(nb / BASE, base, count);
	if (base == 'x')
		*count += write(1, &"0123456789abcdef"[nb % BASE], 1);
	else if (base == 'X')
		*count += write(1, &"0123456789ABCDEF"[nb % BASE], 1);
	else
		*count += write(1, &"0123456789"[nb % BASE], 1);
}
