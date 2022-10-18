#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%6.4s %c %d \n", "Hello", 'A', 42);
	ft_printf("%6.4s %c %d \n", "Hello", 'A', 42);
}
