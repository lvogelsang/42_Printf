/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:37:30 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/17 10:56:16 by lvogelsa         ###   ########.fr       */
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

#include "ft_printf.h"

// If ft_printf (by using ft_format) detects a '%' in str, we determine 
// which flags, widths and conversion types have been specified and print 
// the argument accordingly.
// If there is no %, we simply print the character.

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = ft_format((char *)str, args);
	va_end(args);
	return (len);
}

int	ft_format(char *str, va_list args)
{
	int		len;
	char	*start;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			start = str;
			str++;
			if (*str)
				len = len + ft_format_specifications(str, args);
			while (*str && !(ft_strchr(SPECIFIERS, *str)))
				str++;
			if (!(*str))
				str = start;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	return (len);
}

// Determines the conversion type and refers it to the respective 
// print function.

int	ft_print_type(t_format format, va_list args)
{
	int	len;

	len = 0;
	if (format.type == '%')
		len = ft_print_pct();
	else if (format.type == 'c')
		len = ft_print_c(format, va_arg(args, int));
	else if (format.type == 's')
		len = ft_print_s(format, va_arg(args, char *));
	else if (format.type == 'd' || format.type == 'i')
		len = ft_print_d_i(format, va_arg(args, int));
	else if (format.type == 'u')
		len = ft_print_u(format, va_arg(args, unsigned int));
	else if (format.type == 'X' || format.type == 'x')
		len = ft_print_x(format, va_arg(args, unsigned int));
	else if (format.type == 'p')
		len = ft_print_p(format, va_arg(args, size_t));
	return (len);
}
