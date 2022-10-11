/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:36:23 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/11 15:00:43 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printstring(const char *input, va_list args, size_t len)
{
	int	i;
	char	*s;

	s = va_arg(args, char*);
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	len = len + i;
	while (ft_istype(*input) == 0)
	{
		input++;
	}
}
