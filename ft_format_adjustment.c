/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_adjustment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:39:35 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 18:26:32 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_adjustment(t_format format, char *str)
{
	if (format.minus)
	{
		ft_minus_adjustment(format, str);
	}
	if (format.zero && !(format.minus))
	{
		ft_zero_adjustment(format, str);
	}
	if (!(format.zero) && !(format.minus))
	{
		ft_default_adjustment(format, str);
	}
}

void	ft_minus_adjustment(t_format format, char *str)
{
	int	i;

	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	while (format.width - i)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

void	ft_zero_adjustment(t_format format, char *str)
{
	int	i;

	i = ft_strlen(str);
	while (format.width - i)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putstr_fd(str, 1);
}

void	ft_default_adjustment(t_format format, char *str)
{
	int	i;

	i = ft_strlen(str);
	while (format.width - i)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr_fd(str, 1);
}
