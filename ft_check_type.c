/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:32:49 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/11 15:12:44 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
			|| c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

size_t	ft_check_type(const char *input, va_list args, size_t len)
{
	size_t	i;

	i = 0;
	while (ft_istype(input[i]) == 0)
		i++;
	if (input[i] == 'c')
		len = ft_printcharacter(input, args, len);
	if (input[i] == 's')
		len = ft_printstring(input, args, len);
/*	if (input[i] == 'p')
		ft_printpointer(input, args, i, len);
	if (input[i] == 'd')
		ft_printdecimal(input, args, i, len);
	if (input[i] == 'i')
		ft_printint(input, args, i, len);
	if (input[i] == 'u')
		ft_printunsigneddecimal(input, args, i, len);
	if (input[i] == 'x')
		ft_printhexlow(input, args, i, len);
	if (input[i] == 'X')
		ft_printhexup(input, args, i, len);
	if (input[i] == '%')
		ft_printpercentage(input, args, i, len);*/
	return (len);
}


