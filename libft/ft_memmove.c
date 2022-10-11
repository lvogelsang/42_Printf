/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:58:53 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 10:44:59 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memmove() function copies len bytes from string src to string dst.
//The two strings may overlap; the copy is always done in a non-destructive
//manner.

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	temp[100];

	i = 0;
	while (i < len)
	{
		ft_memset(&temp[i], *(int *)src, 1);
		i++;
		src++;
	}
	i = 0;
	while (i < len)
	{
		ft_memset(&dst[i], temp[i], 1);
		i++;
	}
	return (dst);
}
