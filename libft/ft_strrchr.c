/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:25:15 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/08 10:34:42 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strrchr() function is identical to strchr(), except it locates the last
// occurrence of c.

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	c = c % 256;
	i = ft_strlen(s);
	if (c == '\0')
	{
		s = s + i;
		return ((char *)s);
	}
	s = s + i - 1;
	j = 0;
	while (*s && (j < i))
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		j++;
		s--;
	}
	return (NULL);
}
