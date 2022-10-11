/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:08:00 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/29 14:06:19 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memcpy() function copies n bytes from memory area src to memory area
//dst.  If dst and src overlap, behavior is undefined.

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	n_copy;

	n_copy = n;
	while (n)
	{
		ft_memset(dst, *(int *)src, 1);
		n--;
		dst++;
		src++;
	}
	dst = dst - n_copy;
	return (dst);
}
