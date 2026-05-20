/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:33:03 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 17:33:50 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(void *address)
{
	unsigned long	nbr;
	int				count;

	nbr = (unsigned long)address;
	write (1, "0x", 2);
	count = 2;
	count += ft_printhex('x', nbr);
	return (count);
}
