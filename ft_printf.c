/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:24:46 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 19:39:33 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *	format, ...)
{
	va_list args;
	int		res;
	int		tmp;

	va_start(args, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = check_format(format, &args);
			if (tmp == -1)
				return (-1);
			res += tmp;
			format++;
		}
		if (*format == '\0')
			break ;
		write (1, &*format, 1);
		format++;
		res++;
	}
	va_end(args);
	return (res);
}

int	check_format(const char *format, va_list *args)
{
	if (*format  == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (*format == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (*format == 'p')
		return (ft_printaddress(va_arg(*args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_printnbr(va_arg(*args, int)));
	else if (*format == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (ft_printhex(*format, va_arg(*args, unsigned long)));
	else if (*format == '%')
		return (write (1, "%", 1));
	else
		return (-1);
}
