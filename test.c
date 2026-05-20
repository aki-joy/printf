#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char address[] = "abc";
	ft_printf("%c : ", 'a');
	printf("%c\n", 'a');
	ft_printf("%d : ", 12345);
	printf("%d\n", 12345);
	ft_printf("%s : ", "hello");
	printf("%s\n", "hello");
	ft_printf("%x : ", 65262);
	printf("%x\n", 65262);
	ft_printf("%X : ", 65262);
	printf("%X\n", 65262);
	ft_printf("%p : ", address);
	printf("%p\n", address);
	ft_printf("%u : ", 12345);
	printf("%u\n", 12345);
	ft_printf("%i : ", 12345);
	printf("%i\n", 12345);
	ft_printf("%% : ");
	printf("%%");
	return (0);
}