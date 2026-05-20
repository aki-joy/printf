/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:34:42 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 19:20:49 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(char sign, unsigned long nbr)
{
	char	*base;
	int		count;
	int		ret;

	base = "0123456789abcdef";
	if (sign == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (nbr >= 16)
	{
		ret = ft_printhex(sign, nbr / 16);
		count += ret;
	}
	ret = write (1, &base[nbr % 16], 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
