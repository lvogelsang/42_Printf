/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:43:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 11:19:21 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_d_i(t_specs specs, va_list args)
{
	int	n;
	int	i;
	int	len;

	n = va_args(args, int);
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

void	ft_print_nbr(t_specs specs, int n, int i)
{
	int	neg;
	
	neg = 0;
	if (n < 0)
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
	if (specs.width > 1 && specs.minus)
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

void	ft_print_pad(t_specs specs, int	i, char pad)
{
	while (specs.width - i)
	{
		ft_putchar_fd(pad, 1);
		specs.width--;
	}
}
