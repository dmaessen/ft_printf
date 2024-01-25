/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:06:59 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/23 13:52:52 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int n)
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
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_itoa(int n)
{
	int			len;
	int			i;
	long long	new;
	char		*str;

	len = ft_len(n);
	new = n;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	str[len--] = '\0';
	if (new < 0)
	{
		str[0] = '-';
		new *= -1;
	}
	while (new != 0)
	{
		str[len] = ((new % 10) + '0');
		new = (new / 10);
		len--;
	}
	i = write(1, str, ft_len(n));
	free(str);
	return (i);
}
