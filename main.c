#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{/*
	printf("%6.4s %c %d \n", "Hello", 'A', 42);
	ft_printf("%6.4s %c %d \n", "Hello", 'A', 42);
*///	printf("%.2u\n", 1);
//	printf("%.4d\n", -14);
//	ft_printf("%.2u\n", 1);
//	ft_printf("%.4d\n", -14);
	printf("%5%\n");
	ft_printf("%5%\n");
}

