/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:35:22 by atajima           #+#    #+#             */
/*   Updated: 2026/05/21 02:03:48 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	count;

	if (str == NULL)
		str = "(null)";
	count = 0;
	while (str[count])
	{
		if (write (1, &str[count], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}
