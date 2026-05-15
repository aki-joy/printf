/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:18:39 by atajima           #+#    #+#             */
/*   Updated: 2026/05/15 19:52:31 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *	format, ...)
{
	va_list args;
	int		res;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			if (!check_format(format, args))
				return (-1);
		write (1, &*format, 1);
		format++;
		res++;
	}
	va_end(args);
	return (res);
}

int	check_format(const char *format, va_list args)
{
	format++;
	if (*format  == 'c')
		ft_putstr(va_arg(args, int));
	else if (*format == 's')
		ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		ft_putaddress(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_putnbr(va_arg(args, int));
	else if (*format == 'x' || *format == 'X')
		ft_hexdecimal(format, va_arg(args, unsigned int));
	else if (*format == '%')
		return (ft_putchar('%'));
	else
		return (0);
	format++;
	return (1);	
}
