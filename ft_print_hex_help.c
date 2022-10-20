/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:44:39 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/20 10:23:39 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
char	*ft_hexstr_precision(t_format format, char *hex_str, unsigned int x)
{
	char	*hexstr_format;
	// maybe print 0??
	if (format.precision == 0 && x == 0)
	{
		hexstr_format = (char *)malloc(sizeof(char));
		if (hexstr_format == NULL)
			return (NULL);
		hexstr_format[0] = '\0';
//		printf("%s\n", hexstr_format);
	}
	else if ((format.precision > (int)ft_strlen(hex_str))
		|| ((format.hash) && (format.precision > ((int)ft_strlen(hex_str) - 2))))
	{
		hexstr_format = ft_hexstr_precision2(format, hex_str, x);
	}
	else
	{
		hexstr_format = ft_strdup(hex_str);
	}
	if (hexstr_format == NULL)
		return (NULL);
	return (hexstr_format);
}

char	*ft_hexstr_precision2(t_format format, char *hex_str, unsigned int x)
{
	int	i;
	char	*zero;
	char	*hexstr_format;

	i = 0;
	if (format.hash && x != 0)
		i = 2;
	zero = ft_hexstr_precision_zero(format, hex_str, i); 
	if (zero == NULL)
		return (NULL);
	hexstr_format = ft_strjoin(zero, hex_str + i);
	free (zero);
	if (hexstr_format == NULL)
		return (NULL);
	return (hexstr_format);
}

char	*ft_hexstr_precision_zero(t_format format, char *hex_str, int i)
{
	int	count;
	char	*zero;
	int	j;

	count = format.precision - ft_strlen(hex_str);
	zero = (char *)malloc((count + i) * sizeof(char));
	if (zero == NULL)
		return (NULL);
	j = 0;
	if (format.hash)
	{
		zero[0] = hex_str[0];
		zero[1] = hex_str[1];
		j = j + 2;
	}
	// ?? x
	while (j < (count + i))
	{
		zero[j] = '0';
		j++;
	}
	zero[j] = '\0';
	return (zero);
}
/*

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
}*/
