/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:47:13 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 21:25:38 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(const char *	format, ...);
int	check_format(const char *format, va_list *args);
int	ft_printchar(int n);
int	ft_printstr(char *str);
int	ft_printhex(char sign, unsigned long nbr);
int	ft_printnbr(int nbr);
int	ft_printaddress(void *address);
int	ft_print_unsigned(unsigned int nbr);

#endif