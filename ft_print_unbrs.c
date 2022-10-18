/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:44:36 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/17 15:51:16 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion type 'u'. This type considers the
// '-' & '0' flags and width specifications.

// If a negative value is parsed as an unsigned integer, that value
// is converted to its positive counterpart, i.e., 2^32 - u.
// So, in binary, -u and 2^32 - u are identical.
// Therefore, we cannot use the standard digitcount and itoa functions.

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
