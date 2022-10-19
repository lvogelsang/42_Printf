/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:44:39 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/19 11:06:22 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexstr_precision(t_format format, char *hex_str)
{
	int		x;
	size_t	count;
	char	*copy;
	int		len;

	format.zero = 0;
	if (format.precision > (int)ft_strlen(hex_str))
	{
		x = 0;
		count = format.precision - ft_strlen(hex_str);
		if (format.hash && x != 0)
			x = 2;
		copy = ft_strdup(hex_str + x);
		if (copy == NULL)
			return (0);
		ft_memset(hex_str + x, '0', count + x);
		hex_str[count + x] = '\0';
		len = ft_strlen(hex_str) + ft_strlen(copy);
		ft_strlcat(hex_str, copy, len + 1);
		free (copy);
	}
	return (ft_strlen(hex_str));
}
