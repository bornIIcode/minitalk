/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:29:47 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/23 20:55:11 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n < 0)
	{
		nb = -n;
		count += ft_putchar('-');
	}
	else
		nb = n;
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
