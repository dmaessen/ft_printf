/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:19:29 by dmaessen          #+#    #+#             */
/*   Updated: 2022/11/23 13:54:22 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int	ft_printf(const char *format, ...);
int	ft_conversion(const char format, va_list args);
int	ft_putchar(int c);
int	ft_putpercentage(int c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_utoa(unsigned int input);
int	ft_itoa(int n);
int	ft_puthexa(const char format, unsigned int input);
int	ft_putptr(unsigned long int input);

#endif
