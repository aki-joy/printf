/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:33:03 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 21:08:56 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex_add(char sign, uintptr_t nbr);

int	ft_printaddress(void *address)
{
	uintptr_t	nbr;
	int				count;

	if (address == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	nbr = (uintptr_t)address;
	if (write (1, "0x", 2) == -1)
		return (-1);
	count = 2;
	count += ft_printhex_add('x', nbr);
	return (count);
}

static int	ft_printhex_add(char sign, uintptr_t nbr)
{
	char	*base;
	int		count;
	int		ret;

	base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		ret = ft_printhex_add(sign, nbr / 16);
		count += ret;
	}
	ret = write (1, &base[nbr % 16], 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}