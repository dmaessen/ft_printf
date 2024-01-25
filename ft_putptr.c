/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:19:06 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/21 17:42:41 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenhexa(unsigned long int input)
{
	int	len;

	len = 0;
	while (input != 0)
	{
		len++;
		input /= 16;
	}
	return (len);
}

static int	ft_writehexa(unsigned long int input)
{
	size_t	len;
	size_t	i;
	size_t	mod;
	char	*str;

	len = ft_lenhexa(input);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	i = len - 1;
	str[len] = '\0';
	while (input != 0)
	{
		mod = input % 16;
		if (mod < 10)
			str[i] = (mod + '0');
		else if (mod >= 10)
			str[i] = (mod - 10 + 'a');
		input /= 16;
		i--;
	}
	len = write(1, str, len);
	free(str);
	return (len);
}

int	ft_putptr(unsigned long int input)
{
	int	result;
	int	printed;

	result = 0;
	result += write(1, "0x", 2);
	if (result == -1)
		return (result);
	if (input == 0)
	{
		printed = ft_putchar('0');
		if (printed == -1)
			return (printed);
		result += printed;
	}
	else
	{
		printed = ft_writehexa(input);
		if (printed == -1)
			return (printed);
		result += ft_lenhexa(input);
	}
	return (result);
}
