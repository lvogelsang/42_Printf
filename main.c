#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	i = printf("42%11.26d42", -1543280773);
	printf("\n");
	int	j = ft_printf("42%11.26d42", -1543280773);
	printf("\n");
	printf("%d\t%d", i, j);
}

