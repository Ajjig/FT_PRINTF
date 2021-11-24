/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:27:07 by majjig            #+#    #+#             */
/*   Updated: 2021/11/24 20:36:38 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int nb, char base, int *count)
{
	if (nb >= BASE)
		ft_putunsigned(nb / BASE, base, count);
	if (base == HEXALOWER)
		*count += write(1, &STR_HEXA_LOWER[nb % BASE], 1);
	else if (base == HEXAUPPER)
		*count += write(1, &STR_HEXA_UPPER[nb % BASE], 1);
	else
		*count += write(1, &STR_DECIMAL[nb % BASE], 1);
}
