/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:34:04 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 22:44:53 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_itoa(long nbr);

int	ft_printnbr(int nbr)
{
	int		count;
	long	num;
	int		ret;

	count = 0;
	num = nbr;
	if (nbr < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		count++;
		num *= -1;
	}
	ret = ft_print_itoa(num);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

static int	ft_print_itoa(long nbr)
{
	char	c;
	int		count;
	int		ret;

	count = 0;
	if (nbr >= 10)
	{
		ret = ft_print_itoa(nbr / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = nbr % 10 + '0';
	if (write (1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}
