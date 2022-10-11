/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:16:39 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/11 14:57:00 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	len;

	va_start(args, input);
	len = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			ft_check_type(input, args, len);
			input++;
		}
		else
		{
			write(1, &input[0], 1);
			input++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
