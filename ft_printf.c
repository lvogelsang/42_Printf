/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:37:30 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 19:18:34 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a simplified version of printf which handles the conversions
// "cspdiuxX%" and the flags "-0# +". Here, the syntax of the conversion 
// specifiers is %[flags][width]type. 

// In this project, we need to use variadic functions, which can take a 
// variable number of arguments.

// va_start(va_list ap, last)	
// => Initialises ap. Last is the name of the last parameter before the 
// variable argument list.

// va_arg(va_list ap, type)	
// => Each call modifies ap so that the next call returns the next argument. 
// The first use after va_start() returns the argument after last.

// va_end(va_list ap)	
// => Signals that there are no further arguments.

#include "libftprintf.h"

// If ft_printf detects a '%' in str, we determine which flags, widths and
// conversion types have been specified and print the argument accordingly.
// If there is no %, we simply print the character.

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
			{
				len = len + ft_specs(str, args);
			}
			while (*str && !(ft_strchr(SPECIFIERS, *str)))
			{
				str++;
			}
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}

// Determines the conversion type and refers it to the respective 
// print function.

int	ft_print_specs(t_specs specs, va_list args)
{
	int	len;

	len = 0;
	if (specs.type == 'c' || specs.type == '%')
		len = ft_print_c_pct(specs, args);
	else if (specs.type == 's')
		len = ft_print_s(specs, args);
	else if (specs.type == 'd' || specs.type == 'i' || specs.type == 'u')
		len = ft_print_d_i_u(specs, args);
	else if (specs.type == 'X' || specs.type == 'x')
		len = ft_print_x_X(specs, args);
	else if (specs.type == 'p')
		len = ft_print_p(specs, args);
	return (len);
}
