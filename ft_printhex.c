/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:34:42 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 22:52:20 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(char sign, unsigned int nbr)
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
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = write (1, &base[nbr % 16], 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
