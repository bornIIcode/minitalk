/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:56:24 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/26 10:23:12 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (count);
			count += ft_check_spec(args, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
