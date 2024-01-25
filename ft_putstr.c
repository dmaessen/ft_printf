/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:42:39 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/21 17:07:31 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	writen;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		writen = write(1, &s[i], 1);
		if (writen == -1)
			return (writen);
		i++;
	}
	return (i);
}
