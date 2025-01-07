/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:00 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/24 17:03:51 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int		count;
	char	*hexdigit;

	count = 0;
	if (format == 'X')
		hexdigit = "0123456789ABCDEF";
	else
		hexdigit = "0123456789abcdef";
	if (n > 15)
		count += ft_puthex(n / 16, format);
	count += ft_putchar((hexdigit[n % 16]));
	return (count);
}
