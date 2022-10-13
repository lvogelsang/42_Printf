/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 10:08:20 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Print function for conversion type '%'. This type doesn`t accept any
// flags or width specifications.

int	ft_print_pct(void)
{
	int	len;

	len = 1;
	ft_putchar_fd('%', 1);
	return (len);
}

// Print function for conversion type 'c'. This type considers the '-' flag
// and width specifications.

int	ft_print_c(t_specs specs, va_list args)
{
	char	c;
	int	len;
	
	c = va_args(args, char);
	if (specs.width > 1)
	{
		len = specs.width;
		if (specs.minus)
			ft_putchar_fd(c, 1);
		while (specs.width - 1)
		{
			ft_putchar_fd(' ', 1);
			specs.width--;
		}
		if (!(specs.minus))
			ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		len = 1;
	}
	return (len);
}

// Print function for conversion type 's'. This type considers the '-' flag
// and width specifications.

int	ft_print_s(t_specs specs, va_list args)
{
	char	*str;
	int	i;
	int		len;

	str = va_args(args, char *);
	i = (int)(ft_strlen(str));
	if (specs.width > i)
	{
		len = specs.width;
		if (specs.minus)
			ft_putstr_fd(str, 1);
		while (specs.width - i)
		{
			ft_putchar_fd(' ', 1);
			specs.width;
		}
		if (!(specs.minus))
			ft_putstr_fd(str);
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = i;
	}
	return (len);
}	
