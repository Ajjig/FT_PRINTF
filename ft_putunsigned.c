/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:27:07 by majjig            #+#    #+#             */
/*   Updated: 2021/11/18 03:48:46 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int nb, int *count)
{
	if (nb >= 10)
		ft_putunsigned(nb / 10, count);
	*count += write(1, &"0123456789"[nb % 10],1);
}
