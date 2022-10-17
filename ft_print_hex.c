/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:20:46 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/17 10:59:42 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion types 'x' & 'X'. These types 
// consider the '-', '0', & '#' flags as well as width specifications.

// The base characters for hexadecimal are "0123456789abcdef" and 
// "0123456789ABCDEF", respectively. 
// For conversion from decimal to hexadecimal, keep dividing a decimal number 
// by 16. The hex value of that decimal number is the sequence of remainders 
// (in hex) from the last to the first.

int	ft_print_x(t_format format, unsigned int x)
{
	char	*hex_str;
	int		i;

	hex_str = ft_hexstr(format, x);
	if (hex_str == NULL)
		return (0);
	i = ft_hex_digitcount(x);
	if (format.hash)
		i = i + 2;
	if (format.width > i)
	{
		if (format.zero && !(format.minus)
			&& (format.hash))
		{
			ft_putchar_fd(*hex_str++, 1);
			ft_putchar_fd(*hex_str++, 1);
		}
		ft_format_adjustment(format, hex_str);
		i = format.width;
	}
	else
		ft_putstr_fd(hex_str, 1);
	free (hex_str);
	return (i);
}

char	*ft_hexstr(t_format format, unsigned int x)
{
	char	*prefix;
	char	*temp;
	char	*hex_str;

	if (format.hash)
	{
		prefix = "0x";
		temp = ft_hex_itoa(format, x);
		hex_str = ft_strjoin(prefix, temp);
		free (temp);
	}
	else
	{
		hex_str = ft_hex_itoa(format, x);
	}
	if (hex_str == NULL)
	{
		return (NULL);
	}
	return (hex_str);
}

char	*ft_hex_itoa(t_format format, unsigned int x)
{
	int		i;
	char	*hex_str;
	char	*hex_base;

	i = ft_hex_digitcount(x);
	hex_str = (char *)malloc((i + 1) * sizeof(char));
	if (hex_str == NULL)
		return (NULL);
	hex_str[i] = '\0';
	if (x == 0)
		hex_str[0] = '0';
	if (format.type == 'x')
		hex_base = "0123456789abcdef";
	else if (format.type == 'X')
		hex_base = "0123456789ABCDEF";
	while (x)
	{
		i--;
		hex_str[i] = hex_base[x % 16];
		x = x / 16;
	}
	return (hex_str);
}

int	ft_hex_digitcount(unsigned int x)
{
	int	i;

	if (x == 0)
	{
		return (1);
	}
	i = 0;
	while (x)
	{
		x = x / 16;
		i++;
	}
	return (i);
}