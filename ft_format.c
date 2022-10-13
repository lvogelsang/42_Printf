/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:11:01 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 17:37:13 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// First calls functions to test for flags and width and then determines the
// conversion type. All this will be stored in the new structure 'specs'. 

int	ft_format_specifications(char *str, va_list args)
{
	t_format	format;
	int		len;

	format = ft_format_default();
	format = ft_format_flags(str, format);
	format = ft_format_width(str, format);
	while (!(ft_strchr(SPECIFIERS, *str)))
	{
		str++;
	}
	format.type = *str;
	len = ft_print_type(format, args);
	return (len);
}

// Tests for the flags '+', ' ', and '#'.

t_format	ft_format_flags(char *str, t_format format)
{
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '+')
		{
			format.plus = 1;
		}
		if (*str == ' ')
		{
			format.space = 1;
		}
		if (*str == '#')
		{
			format.hash = 1;
		}
		str++;
	}
	return (format);
}

// Tests for width specifications, including the flags '-' and '0', and for the 
// actual width. 

t_format	ft_format_width(char *str, t_format format)
{
	while (!(ft_strchr(SPECIFIERS, *str)))
	{
		if (*str == '-')
		{
			format.minus = 1;
		}
		if (*str == '0' && !(ft_isdigit(*(str - 1))))
		{
			format.zero = 1;
		}
		if (*str > '0' && *str <= '9')
		{
			format.width = ft_atoi(str);
			break ;
		}
		str++;
	}
	return (format);
}
