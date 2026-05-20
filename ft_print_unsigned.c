/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:38:17 by atajima           #+#    #+#             */
/*   Updated: 2026/05/21 02:06:18 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_itoa(unsigned int nbr);

int	ft_print_unsigned(unsigned int nbr)
{
	int				count;
	unsigned int	tmp;

	count = 1;
	tmp = nbr;
	while (tmp >= 10)
	{
		tmp /= 10;
		count++;
	}
	if (!ft_print_itoa(nbr))
		return (-1);
	return (count);
}

static int	ft_print_itoa(unsigned int nbr)
{
	char	c;

	if (nbr >= 10)
	{
		if (ft_print_itoa(nbr / 10) == 0)
			return (0);
	}
	c = nbr % 10 + '0';
	if (write (1, &c, 1) == -1)
		return (0);
	return (1);
}
