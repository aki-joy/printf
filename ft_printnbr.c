/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:34:04 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 17:54:26 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr)
{
	char	*str;
	int		count;

	str = ft_itoa(nbr);
	if (!str)
		return (0);
	count = 0;
	while (str[count])
	{
		write (1, &str[count], 1);
		count++;
	}
	free(str);
	return (count);
}
