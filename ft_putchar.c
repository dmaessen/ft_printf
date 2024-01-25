/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:13 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/22 15:48:47 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_writechar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar(int c)
{
	return (ft_writechar(c));
}
