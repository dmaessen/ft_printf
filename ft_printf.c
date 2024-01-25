/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:18 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/28 13:37:29 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char format, va_list args)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (format == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		result += ft_putptr(va_arg(args, unsigned long int));
	else if (format == 'd' || format == 'i')
		result += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		result += ft_utoa(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result += ft_puthexa(format, va_arg(args, unsigned int));
	else if (format == '%')
		result += ft_putpercentage('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	int		printed;
	va_list	args;

	va_start(args, format);
	i = 0;
	result = 0;
	while (format[i])
	{	
		printed = 0;
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			printed = ft_conversion(format[i + 1], args);
			i++;
		}
		else if (format[i] != '%')
			printed = write(1, &format[i], 1);
		if (printed == -1)
			return (printed);
		result += printed;
		i++;
	}
	va_end(args);
	return (result);
}
