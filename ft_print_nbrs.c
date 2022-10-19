/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:43:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/19 17:02:42 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion types 'd' and 'i'. These types consider 
// the '+', ' ', '-', & '0' flags as well as width and
// precision specifications.

int	ft_print_d_i(t_format format, int n)
{
	char	*num_str;
	int		i;
	int		len;

	num_str = ft_numstr_signed(format, n);
	if (num_str == NULL)
		return (0);
	if (format.dot)
	{
		format.zero = 0;
		i = ft_numstr_precision(format, num_str, n);
	}
	else
		i = ft_strlen(num_str);
	if (format.width > i)
	{
		len = format.width;
		ft_numstr_help(format, num_str, n);
	}
	else
	{
		len = i;
		ft_putstr_fd(num_str, 1);
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

int	ft_numstr_precision(t_format format, char *num_str, int n)
{
	int		x;
	size_t	count;
	char	*copy;
	int		len;

	if (format.precision == 0)
	{
		num_str[0] = '\0';
	}
	if ((format.precision > (int)ft_strlen(num_str))
		|| ((format.plus || format.space || (n < 0))
			&& (format.precision == (int)ft_strlen(num_str))))
	{
		x = 0;
		count = format.precision - ft_strlen(num_str);
		if (format.plus || format.space || (n < 0))
			x = 1;
		copy = ft_strdup(num_str + x);
		if (copy == NULL)
			return (0);
		ft_memset(num_str + x, '0', count + x);
		num_str[count + 2 * x] = '\0';
		len = ft_strlen(num_str) + ft_strlen(copy);
		ft_strlcat(num_str, copy, len + 1);
		free (copy);
	}
	return (ft_strlen(num_str));
}

void	ft_numstr_help(t_format format, char *num_str, int n)
{
	int	x;

	x = 0;
	if (format.zero && !(format.minus)
		&& (format.plus || format.space || (n < 0)))
	{
		ft_putchar_fd(num_str[x], 1);
		x++;
		format.width--;
	}
	ft_format_adjustment(format, &num_str[x]);
}
