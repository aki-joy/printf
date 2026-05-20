#include "printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_printhex(char sign, unsigned int nbr)
{
	char	*base;
	int		n;
	int		count;
	int		ret;

	if (sign == 'x')
		base = "0123456789abcdef";
	if (sign == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (nbr >= 16)
	{
		ret = ft_printhex(sign, nbr / 16);
		count += ret;
	}
	n = nbr % 16;
	ret = write (1, &base[n], 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int main(void)
{
	int nbr = 65262;
	nbr = ft_printhex('X',nbr);
	printf("\n%d", nbr);
	return (0);
}