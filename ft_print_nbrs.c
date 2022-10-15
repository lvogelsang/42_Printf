/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:43:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/15 15:28:03 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion types 'd' and 'i'. These types consider 
// the '+', ' ', '-', & '0' flags as well as width specifications.

int	ft_print_d_i(t_format format, int n)
{
	char	*num_str;
	int		i;
	int		len;

	num_str = ft_numstr_signed(format, n);
	if (num_str == NULL)
		return (0);
	i = ft_digitcount(n);
	if ((format.plus || format.space) && n >= 0)
		i++;
	if (format.width > i)
	{
		if (format.zero && !(format.minus)
			&& (format.plus || format.space))
			ft_putchar_fd(num_str[0], 1);
		ft_format_adjustment(format, ++num_str);
		len = format.width;
	}
	else
	{
		ft_putstr_fd(num_str, 1);
		len = i;
	}
	free (num_str);
	return (len);
}

char	*ft_numstr_signed(t_format format, int n)
{
	char	*sign;
	char	*temp;
	char	*numstr;

	if ((format.plus || format.space) && n >= 0)
	{
		if (format.plus)
			sign = "+";
		else if (format.space)
			sign = " ";
		temp = ft_itoa(n);
		numstr = ft_strjoin(sign, temp);
		free (temp);
	}
	else
		numstr = ft_itoa(n);
	if (numstr == NULL)
		return (NULL);
	return (numstr);
}

// Print function for the conversion type 'u'. This type considers the 
// '-' & '0' flags and width specifications.

int	ft_print_u(t_format format, unsigned int u)
{
	char	*num_str;
	int		i;
	int		len;

	num_str = ft_unsigned_itoa(u);
	if (num_str == NULL)
	{
		return (0);
	}
	i = ft_unsigned_digitcount(u);
	if (format.width > i)
	{
		ft_format_adjustment(format, num_str);
		len = format.width;
	}
	else
	{
		ft_putstr_fd(num_str, 1);
		len = i;
	}
	free (num_str);
	return (len);
}

char	*ft_unsigned_itoa(unsigned int u)
{
	int		i;
	char	*num_str;

	i = ft_unsigned_digitcount(u);
	num_str = (char *)malloc((i + 1) * sizeof(char));
	if (num_str == NULL)
	{
		return (NULL);
	}
	num_str[i] = '\0';
	if (u == 0)
	{
		num_str[0] = '0';
	}
	while (u)
	{
		i--;
		num_str[i] = u % 10 + 48;
		u = u / 10;
	}
	return (num_str);
}

int	ft_unsigned_digitcount(unsigned int u)
{
	int	i;

	if (u == 0)
	{
		return (1);
	}
	i = 0;
	while (u)
	{
		i++;
		u = u / 10;
	}
	return (i);
}
