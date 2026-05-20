/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:38:17 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 21:20:43 by atajima          ###   ########.fr       */
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
	if(!ft_print_itoa(nbr))
		return (-1);
	return (count);
}

static int	ft_print_itoa(unsigned int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_print_itoa(nbr / 10);
	c = nbr % 10 +'0';
	if (write (1, &c, 1) == -1)
		return (0);
	return (1);
}