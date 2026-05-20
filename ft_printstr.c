/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:35:22 by atajima           #+#    #+#             */
/*   Updated: 2026/05/20 17:35:35 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int	ft_printstr(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
	{
		if (!write (1, &str[count], 1))
			return (-1);
		count++;
	}
	return (count);
}
