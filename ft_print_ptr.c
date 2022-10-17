/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:47:15 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/17 11:01:27 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion type 'p'. This type considers
// the '-' & '0' flags as well as width specifications.

// The address of a pointer is in hexadecimal format, so we use similar
// methods to the conversion types 'x' & 'X'. The main difference is that
// we use size_t instead of unsigned int as size_t can get as big as the
// addressable memory space, while unsigned int has a minimum range.

int	ft_print_p(t_format format, size_t ptr)
{
	char	*ptr_str;
	int		i;

	ptr_str = ft_ptrstr(ptr);
	if (ptr_str == NULL)
		return (0);
	i = ft_ptr_digitcount(ptr);
	i = i + 2;
	if (format.width > i)
	{
		if (format.zero && !(format.minus))
		{
			ft_putchar_fd(*ptr_str++, 1);
			ft_putchar_fd(*ptr_str++, 1);
		}
		ft_format_adjustment(format, ptr_str);
		i = format.width;
	}
	else
		ft_putstr_fd(ptr_str, 1);
	free (ptr_str);
	return (i);
}

char	*ft_ptrstr(size_t ptr)
{
	char	*prefix;
	char	*temp;
	char	*ptr_str;

	prefix = "0x";
	temp = ft_ptr_itoa(ptr);
	ptr_str = ft_strjoin(prefix, temp);
	free (temp);
	if (ptr_str == NULL)
	{
		return (NULL);
	}
	return (ptr_str);
}

char	*ft_ptr_itoa(size_t ptr)
{
	int		i;
	char	*ptr_str;
	char	*hex_base;

	i = ft_ptr_digitcount(ptr);
	ptr_str = (char *)malloc((i + 1) * sizeof(char));
	if (ptr_str == NULL)
		return (NULL);
	ptr_str[i] = '\0';
	if (ptr == 0)
		ptr_str[0] = '0';
	hex_base = "0123456789abcdef";
	while (ptr)
	{
		i--;
		ptr_str[i] = hex_base[ptr % 16];
		ptr = ptr / 16;
	}
	return (ptr_str);
}

int	ft_ptr_digitcount(size_t ptr)
{
	int	i;

	if (ptr == 0)
	{
		return (1);
	}
	i = 0;
	while (ptr)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}
