#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{

	printf("15 %04d ", -14);
	printf("16 %05d ", -15);
	printf("17 %06d ", -16);
/*	printf("23 %011d ", LONG_MAX);
	printf("25 %013d ", UINT_MAX);
	printf("26 %014d ", ULONG_MAX);
	printf("27 %015d ", 9223372036854775807LL);
	printf("28 %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/
	printf("\n");
	ft_printf("15 %04d ", -14);
	ft_printf("16 %05d ", -15);
	ft_printf("17 %06d ", -16);
/*	ft_printf("23 %011d ", LONG_MAX);
	ft_printf("25 %013d ", UINT_MAX);
	ft_printf("26 %014d ", ULONG_MAX);
	ft_printf("27 %015d ", 9223372036854775807LL);
	ft_printf("28 %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/
	/*
	printf("1%c", '0');
	printf("2 %c ", '0');
	printf("3 %c", '0' - 256);
	printf("4%c ", '0' + 256);
	printf("5 %c %c %c ", '0', 0, '1');
	printf("6 %c %c %c ", ' ', ' ', ' ');
	printf("7 %c %c %c ", '1', '2', '3');
	printf("8 %c %c %c ", '2', '1', 0);
	printf("9 %c %c %c ", 0, '1', '2');
	printf("\n");
	ft_printf("1%c", '0');
	ft_printf("2 %c ", '0');
	ft_printf("3 %c", '0' - 256);
	ft_printf("4%c ", '0' + 256);
	ft_printf("5 %c %c %c ", '0', 0, '1');
	ft_printf("6 %c %c %c ", ' ', ' ', ' ');
	ft_printf("7 %c %c %c ", '1', '2', '3');
	ft_printf("8 %c %c %c ", '2', '1', 0);
	ft_printf("9 %c %c %c ", 0, '1', '2');
	int	i = printf("%c", 0);
	int	j = ft_printf("%c", 0);
	printf("%d\n%d\n", i, j);
	int	i = printf("%-2c", '0');
	printf("\n%d\n", i);
	printf("%-3c", '0' - 256);
	printf("%-4c", '0' + 256);
	printf("%-1c %-2c %-3c", '0', 0, '1');
	printf("%-1c %-2c %-3c", ' ', ' ', ' ');
	printf("%-1c %-2c %-3c", '1', '2', '3');
	printf("%-1c %-2c %-3c", '2', '1', 0);
	printf("%-1c %-2c %-3c\n", 0, '1', '2');
	
	int	j =ft_printf("%-2c", '0');
	ft_printf("\n%d\n", j);
	ft_printf("%-3c", '0' - 256);
	ft_printf("%-4c", '0' + 256);
	ft_printf("%-1c %-2c %-3c", '0', 0, '1');
	ft_printf("%-1c %-2c %-3c", ' ', ' ', ' ');
	ft_printf("%-1c %-2c %-3c", '1', '2', '3');
	ft_printf("%-1c %-2c %-3c", '2', '1', 0);
	ft_printf("%-1c %-2c %-3c\n", 0, '1', '2');
	printf(" %-1c %-2c %-3c \n", '0', 0, '1');
	ft_printf(" %-1c %-2c %-3c \n", '0', 0, '1');
	printf(" %-1c %-2c %-3c \n", '2', '1', 0);
	ft_printf(" %-1c %-2c %-3c \n", '2', '1', 0);*/
}
