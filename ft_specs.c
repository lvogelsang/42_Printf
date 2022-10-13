/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:11:01 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 14:53:50 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// First calls functions to test for flags and width and then determines the
// conversion type. All this will be stored in the new structure 'specs'. 

int	ft_specs(char *str, va_list args)
{
	t_specs	specs;
	int		len;

	specs = ft_specs_default();
	specs = ft_specs_flags(str, specs);
	specs = ft_specs_width(str, specs);
	while (!(ft_strchr(SPECIFIERS, *str)))
	{
		str++;
	}
	specs.type = *str;
	len = ft_print_specs(specs, args);
	return (len);
}

// Tests for the flags '+', ' ', and '#'.

t_specs	ft_specs_flags(char *str, t_specs specs)
{
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '+')
		{
			specs.plus = 1;
		}
		if (*str == ' ')
		{
			specs.space = 1;
		}
		if (*str == '#')
		{
			specs.hash = 1;
		}
		str++;
	}
	return (specs);
}

// Tests for width specifications, including the flags '-' and '0', and for the 
// actual width. 

t_specs	ft_specs_width(char *str, t_specs specs)
{
	while (!(ft_strchr(SPECIFIERS, *str)))
	{
		if (*str == '-')
		{
			specs.minus = 1;
		}
		else if (*str == '0' && !(ft_isdigit(*(str - 1))))
		{
			specs.zero = 1;
		}
		else if (*str > '0' && *str <= '9')
		{
			specs.width = ft_atoi(str);
			break ;
		}
		str++;
	}
	return (specs);
}
