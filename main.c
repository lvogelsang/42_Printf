#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	i = printf("%.50u\n", 100);
	int	j = ft_printf("%.50u\n", 100);
	printf("%d\n%d\n", i, j);
//	printf("%.0d\n", 2);
//	ft_printf("%.0d", 2);
	/*
	printf("%6.4s %c %d \n", "Hello", 'A', 42);
	ft_printf("%6.4s %c %d \n", "Hello", 'A', 42);
*///	printf("%.2u\n", 1);
//	printf("%.4d\n", -14);
//	ft_printf("%.2u\n", 1);
//	ft_printf("%.4d\n", -14);
//	ft_printf("%.20d\n", -1024);
//	printf("%.20d\n", -1024);
}

