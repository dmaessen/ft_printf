/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:15:04 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/23 13:45:10 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lennbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int		printed;
	int		len;

	len = ft_lennbr(n);
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putstr("0"));
	else
	{
		printed = ft_itoa(n);
		if (printed == -1)
			return (printed);
	}
	return (len);
}
