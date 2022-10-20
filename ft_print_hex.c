/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:20:46 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/20 10:16:04 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion types 'x' & 'X'. These types 
// consider the '-', '0', & '#' flags as well as width and 
// precision specifications.

// The base characters for hexadecimal are "0123456789abcdef" and 
// "0123456789ABCDEF", respectively. 
// For conversion from decimal to hexadecimal, keep dividing a decimal number 
// by 16. The hex value of that decimal number is the sequence of remainders 
// (in hex) from the last to the first.

int	ft_print_x(t_format format, unsigned int x)
{
	char	*hexstr;
	int	i;
	int	len;

	hexstr = ft_hexstr_x(format, x);
	if (hexstr == NULL)
		return (0);
	if (format.dot)
		format.zero = 0;
	i = ft_strlen(hexstr);
	if (format.width > i)
	{
		len = format.width;
		ft_hexstr_help(format, hexstr, x);
	}
	else
	{
		len = i;
		ft_putstr_fd(hexstr, 1);
	}
	free (hexstr);
	return (len);
}
/*
int	ft_print_x(t_format format, unsigned int x)
{
	char	*hex_str;
	int		i;

	hex_str = ft_hexstr(format, x);
	if (hex_str == NULL)
		return (0);
	if (format.dot)
	{
		format.zero = 0;
		i = ft_hexstr_precision(format, hex_str);
	}
	else
		i = ft_strlen(hex_str);
	if (format.width > i)
	{
		i = format.width;
		ft_hexstr_help(format, hex_str, x);
	}
	else
		ft_putstr_fd(hex_str, 1);
	free (hex_str);
	return (i);
}*/

char	*ft_hexstr_x(t_format format, unsigned int x)
{
	char	*hexstr;
	char	*hexstr_format;

	hexstr = ft_hexstr(format, x);
	if (hexstr == NULL)
		return (NULL);
	if (format.dot)
	{
		hexstr_format = ft_hexstr_precision(format, hexstr, x);
	}
	else
	{
		hexstr_format = ft_strdup(hexstr);
	}
	free (hexstr);
	if (hexstr_format == NULL)
		return (NULL);
	return (hexstr_format);
}

char	*ft_hexstr(t_format format, unsigned int x)
{
	char	*hex_base;
	char	*prefix;
	char	*temp;
	char	*hex_str;
	
	// check if x is already a hex number.
	if (format.type == 'x')
		hex_base = "0123456789abcdef";
	else if (format.type == 'X')
		hex_base = "0123456789ABCDEF";
	if (format.hash && x != 0)
	{
		if (format.type == 'x')
			prefix = "0x";
		else if (format.type == 'X')
			prefix = "0X";
		temp = ft_hex_itoa(x, hex_base);
		hex_str = ft_strjoin(prefix, temp);
		free (temp);
	}
	else
		hex_str = ft_hex_itoa(x, hex_base);
	if (hex_str == NULL)
		return (NULL);
	return (hex_str);
}

char	*ft_hex_itoa(unsigned int x, char *hex_base)
{
	int		i;
	char	*hex_str;
	
	i = ft_hex_digitcount(x);
	hex_str = (char *)malloc((i + 1) * sizeof(char));
	if (hex_str == NULL)
		return (NULL);
	hex_str[i] = '\0';
	if (x == 0)
		hex_str[0] = '0';
	if (x == 80000000)
	{
		hex_str = "80000000";
		return (hex_str);
	}
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
	if (x == 80000000)
	{
		return (8);
	}
	i = 0;
	while (x)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

void	ft_hexstr_help(t_format format, char *hex_str, unsigned int x)
{
	int	j;

	j = 0;
	if (format.zero && !(format.minus)
		&& (format.hash) && x != 0)
	{
		ft_putchar_fd(hex_str[j++], 1);
		ft_putchar_fd(hex_str[j++], 1);
		format.width = format.width - 2;
	}
	ft_format_adjustment(format, &hex_str[j]);
}
