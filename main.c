#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%-2c", '0');
	printf("%-3c", '0' - 256);
	printf("%-4c", '0' + 256);
	printf("%-1c %-2c %-3c", '0', 0, '1');
	printf("%-1c %-2c %-3c", ' ', ' ', ' ');
	printf("%-1c %-2c %-3c", '1', '2', '3');
	printf("%-1c %-2c %-3c", '2', '1', 0);
	printf("%-1c %-2c %-3c\n", 0, '1', '2');
	
	ft_printf("%-2c", '0');
	ft_printf("%-3c", '0' - 256);
	ft_printf("%-4c", '0' + 256);
	ft_printf("%-1c %-2c %-3c", '0', 0, '1');
	ft_printf("%-1c %-2c %-3c", ' ', ' ', ' ');
	ft_printf("%-1c %-2c %-3c", '1', '2', '3');
	ft_printf("%-1c %-2c %-3c", '2', '1', 0);
	ft_printf("%-1c %-2c %-3c\n", 0, '1', '2');
}
