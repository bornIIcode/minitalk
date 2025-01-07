/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:49:04 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/24 20:14:00 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_spec(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else
		count += ft_putchar(format);
	return (count);
}
