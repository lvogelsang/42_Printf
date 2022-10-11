/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcharacter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:52:08 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/11 15:13:37 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_printcharacter(const char *input, va_list args, size_t len)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	len++;
	while (ft_istype(*input) == 0)
	{
		input++;
	}
	return (len);
}
