/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:18:00 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/21 16:27:27 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_len(unsigned int input)
{
	size_t	len;

	len = 0;
	if (input == 0)
		return (1);
	while (input >= 1)
	{
		len++;
		input /= 10;
	}
	return (len);
}

int	ft_utoa(unsigned int input)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_len(input);
	i = len;
	if (input == 0)
	{
		i = write(1, "0", 1);
		return (i);
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	len--;
	while (len)
	{
		str[len] = ((input % 10) + '0');
		input /= 10;
		len--;
	}
	str[0] = ((input % 10) + '0');
	i = write(1, str, i);
	free(str);
	return (i);
}
