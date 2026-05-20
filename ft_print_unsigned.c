/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:38:17 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 18:09:07 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_itoa(unsigned int nbr);

int	ft_print_unsigned(unsigned int nbr)
{
	int				count;
	unsigned int	tmp;

	count = 0;
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	ft_print_itoa(nbr);
	return (count);
}

static void	ft_print_itoa(unsigned int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_print_itoa(nbr / 10);
	c = nbr % 10 +'0';
	write (1, &c, 1);
}