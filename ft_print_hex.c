/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:20:46 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 15:00:28 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion types 'x', 'X' & 'p'. These types 
// consider the '-', '0', & '#' flags as well as width specifications.

// The base characters for hexadecimal are "0123456789abcdef" and 
// "0123456789ABCDEF", respectively. 
// For conversion from decimal to hexadecimal, keep dividing a decimal number 
// by 16. The hex value of that decimal number is the sequence of remainders 
// (in hex) from the last to the first.

// The address of a pointer is in hexadecimal format.

int	ft_print_x_p(t_specs specs, va_list args)
{
	unsigned int	x;
	char			*hex_str;
	int				i;
	int				len;

	x = va_arg(args, unsigned int);
	hex_str = ft_conv_hex(specs, x);
	i = ft_strlen(hex_str);
	if (specs.type == 'p')
		specs.hash = 1;
	if (specs.hash)
		i = i + 2;
	ft_print_hex(specs, hex_str, i);
	free (hex_str);
	if (specs.width > i)
	{
		len = specs.width;
	}
	else
	{
		len = i;
	}
	return (len);
}

// Helper functions for printing the conversion types 'x', 'X', & 'p'.

char	*ft_conv_hex(t_specs specs, unsigned int x)
{
	char	*hex_base;
	int		i;
	char	*hex_str;
	int		rem;

	if (specs.type == 'x' || specs.type == 'p')
		hex_base = "0123456789abcdef";
	else if (specs.type == 'X')
		hex_base = "0123456789ABCDEF";
	i = 0;
	hex_str = (char *)malloc(100 * sizeof(char));
	if (x == 0)
	{
		hex_str[i] = 0;
	}
	rem = 0;
	while (x)
	{
		rem = x % 16;
		x = x / 16;
		hex_str[i] = hex_base[rem];
		i++;
	}
	return (hex_str);
}

void	ft_print_hex(t_specs specs, char *hex_str, int i)
{
	if ((specs.minus || specs.zero || i >= specs.width
			|| specs.type == 'p') && specs.hash)
	{
		ft_putstr_fd("0x", 1);
	}
	if (specs.width > i && specs.zero && !(specs.minus))
	{
		ft_print_pad(specs, i, '0');
	}
	if (specs.width > i && !(specs.zero) && !(specs.minus))
	{
		ft_print_pad(specs, i, ' ');
		if (specs.hash)
		{
			ft_putstr_fd("0x", 1);
		}
	}
	ft_putstr_fd(hex_str, 1);
	if (specs.width > i && specs.minus)
	{
		ft_print_pad(specs, i, ' ');
	}
}
