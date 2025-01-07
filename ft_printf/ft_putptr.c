/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:14:08 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/24 20:01:59 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(unsigned long n, char format)
{
	int		count;
	char	*hexdigit;

	count = 0;
	if (format == 'X')
		hexdigit = "0123456789ABCDEF";
	else
		hexdigit = "0123456789abcdef";
	if (n > 15)
		count += ft_puthex_long(n / 16, format);
	count += ft_putchar((hexdigit[n % 16]));
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	adresse;

	count = 0;
	adresse = (unsigned long)ptr;
	count += ft_putstr("0x");
	if (adresse == 0)
		count += ft_putchar('0');
	else
		count += ft_puthex_long(adresse, 'x');
	return (count);
}
