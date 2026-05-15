/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:40:58 by atajima           #+#    #+#             */
/*   Updated: 2026/05/15 20:00:49 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, &*str, 1);
		str++;
	}
}

void	ft_putaddress(void *address)
{
	unsigned long	addr;

	addr = address;
	
}

int ft_hexdecimal(char c, unsigned int hex)
{
	
}