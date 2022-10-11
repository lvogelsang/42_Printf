/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:37:51 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/08 11:35:04 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the integer n to the given file descriptor.

#include "libft.h"

/*
void	ft_putnbr_fd(int n, int fd)
{
	char	*numstr;

	numstr = ft_itoa(n);
	ft_putstr_fd(numstr, fd);
	free (numstr);
}*/

void	ft_putnbr(int n, int fd)
{
	int	x;

	x = 0;
	while (n != 0)
	{
		x = (x * 10) + (n % 10);
		n = n / 10;
	}
	while (x != 0)
	{
		ft_putchar_fd((x % 10) + 48, fd);
		x = x / 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	zero;

	zero = 0;
	if (n == 0)
		ft_putchar_fd(n + 48, fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 2147483647)
		ft_putstr_fd("2147483647", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * (-1);
		}
		if ((n % 10) == 0)
			zero = 1;
		ft_putnbr(n, fd);
	}
	if (zero == 1)
		ft_putchar_fd('0', fd);
}
