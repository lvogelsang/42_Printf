/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:43:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/14 12:44:11 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion types 'd' and 'i'. These types consider 
// the '+', ' ', '-', & '0' flags as well as width specifications.


// digitcount (check if sign needs to be icnorparted) and create malloc with itoa!
// if format.plus or format.space append + or blank to start nbr
// if format.zero & (!(format.minus) && fomrat.plus || format.blank,
// write sign (str[i]), then send str + 1 to format_adjustments
//
// // incorporate x = 0 !!!! for both (includes in itoa);

// for 'u': digitcount, if n < 0, -n, malloc, ft_itoa, send off to format_adjutsments.



int	ft_print_d_i(t_format format, int n)
{
	int		i;
	char	*numstr;
	char	sign;

	numstr = ft_itoa(n);
	i = ft_digitcount(n);
	if ((format.plus || format.space) && n > 0)
	{
		i++;
		if (format.plus)
		{
			sign = "+";
		}
		else if (format.space)
		{
			sign = " ";
		}
		numstr = ft_strjoin(sign, ft_itoa(n), i);






int	ft_print_d_i(t_specs specs, va_list args)
{
	int	n;
	int	i;
	int	len;

	n = va_arg(args, int);
	i = ft_digitcount(n);
	if (specs.plus || specs.space || n < 0)
	{
		i = i + 1;
	}
	ft_print_nbr(specs, n, i);
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

// Print function for the conversion type 'u'. This type considers the 
// '-' & '0' flags and width specifications.

int	ft_print_u(t_specs specs, va_list args)
{
	unsigned int	u;
	int				i;
	int				len;

	u = va_arg(args, unsigned int);
	i = ft_digitcount(u);
	specs.plus = 0;
	specs.space = 0;
	if (u < 0)
	{
		u = u * (-1);
	}
	ft_print_nbr(specs, u, i);
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

// Helper functions for printing the conversion types 'd', 'i', & 'u'.

void	ft_print_nbr(t_specs specs, int n, int i)
{
	int	neg;

	neg = 0;
	if (n < 0 && n != -2147483648)
	{
		neg = 1;
		n = n * (-1);
	}
	if (specs.minus || specs.zero || i >= specs.width)
		ft_print_sign(specs, neg);
	if (specs.width > i && specs.zero && !(specs.minus))
		ft_print_pad(specs, i, '0');
	if (specs.width > i && !(specs.zero) && !(specs.minus))
	{
		ft_print_pad(specs, i, ' ');
		ft_print_sign(specs, neg);
	}
	ft_putnbr_fd(n, 1);
	if (specs.width > i && specs.minus)
		ft_print_pad(specs, i, ' ');
}

void	ft_print_sign(t_specs specs, int neg)
{
	if (neg)
	{
		ft_putchar_fd('-', 1);
	}
	else if (specs.plus)
	{
		ft_putchar_fd('+', 1);
	}
	else if (specs.space)
	{
		ft_putchar_fd(' ', 1);
	}
}

void	ft_print_pad(t_specs specs, int i, char pad)
{
	while (specs.width - i)
	{
		ft_putchar_fd(pad, 1);
		specs.width--;
	}
}
