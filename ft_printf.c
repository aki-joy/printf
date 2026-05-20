/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:24:46 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 23:02:33 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;
	int		tmp;

	va_start(args, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
			tmp = check_format(++format, &args);
		else
			tmp = write (1, format, 1);
		if (tmp == -1)
		{
			va_end(args);
			return (-1);
		}
		res += tmp;
		format++;
	}
	va_end(args);
	return (res);
}

int	check_format(const char *format, va_list *args)
{
	if (*format == 'c')
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
		return (ft_printhex(*format, va_arg(*args, unsigned int)));
	else if (*format == '%')
		return (write (1, "%", 1));
	else
		return (-1);
}
