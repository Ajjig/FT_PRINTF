/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 04:08:32 by majjig            #+#    #+#             */
/*   Updated: 2021/11/18 04:17:44 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(unsigned long nb, int *count)
{
	if (nb > 10)
		ft_putlong(nb / 10, count);
	count += write(1, &"0123456789"[nb % 10], 1);
}

void	ft_putad(unsigned long nb, int *count)
{
	*count += write(1, "0x", 1);
	ft_putlong(nb, count);
}
