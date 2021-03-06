/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 04:08:32 by majjig            #+#    #+#             */
/*   Updated: 2021/11/24 20:28:05 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(unsigned long int nb, int *count)
{
	if (nb >= 16)
		ft_putlong(nb / 16, count);
	*count += write(1, &STR_HEXA_LOWER[nb % 16], 1);
}

void	ft_putad(unsigned long int nb, int *count)
{
	*count += write(1, "0x", 2);
	ft_putlong(nb, count);
}
