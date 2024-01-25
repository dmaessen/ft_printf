/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:03 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/21 16:18:31 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lenhexa(unsigned int input)
{
	size_t	len;

	len = 0;
	if (input == 0)
		return (1);
	while (input >= 1)
	{
		len++;
		input /= 16;
	}
	return (len);
}

static void	ft_mod(unsigned int input, char *str, size_t i)
{
	size_t	mod;

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
}

static void	ft_upper(const char format, char *str)
{
	size_t	i;

	if (format == 'X')
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
}

int	ft_puthexa(const char format, unsigned int input)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_lenhexa(input);
	if (input == 0)
	{
		len = write(1, "0", 1);
		return (len);
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	i = len - 1;
	str[len] = '\0';
	ft_mod(input, str, i);
	ft_upper(format, str);
	len = write(1, str, len);
	free(str);
	return (len);
}
