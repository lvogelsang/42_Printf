/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/15 14:02:27 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_c(t_format format, int c)
{
	int	len;

	if (format.width > 1)
	{
		if (format.minus)
		{
			ft_putchar_fd(c, 1);
		}
		while (format.width - 1)
		{
			ft_putchar_fd(' ', 1);
			format.width--;
		}
		if (!(format.minus))
		{
			ft_putchar_fd(c, 1);
		}
		len = format.width;
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

int	ft_print_s(t_format format, char *s)
{
	int		i;
	char	*s_str;
	int		len;

	if (!(s))
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	s_str = ft_strdup(s);
	if (s_str == NULL)
		return (0);
	i = ft_strlen(s_str);
	if (format.width > i)
	{
		ft_format_adjustment(format, s_str);
		len = format.width;
	}
	else
	{
		ft_putstr_fd(s_str, 1);
		len = i;
	}
	free (s_str);
	return (len);
}
