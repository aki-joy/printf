/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:18:39 by atajima           #+#    #+#             */
/*   Updated: 2026/05/15 20:55:14 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *	format, ...)
{
	va_list args;
	int		res;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			format = check_format(format, args);
		else if (*format != '%' && !*format)
			write (1, &*format, 1);
		format++;
		res++;
	}
	va_end(args);
	return (res);
}

char	*check_format(const char *format, va_list args)
{
	format++;
	if (*format  == 'c')
		ft_putstr(va_arg(args, int));
	else if (*format == 's')
		ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		ft_putaddress(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i') 
		ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		ft_hexdecimal(format, va_arg(args, unsigned int));
	else if (*format == '%')
		return (ft_putchar('%'));
	format++;	
}
