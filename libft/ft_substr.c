/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:28:17 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/09 10:26:45 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a substring from the string s. The substring begins at index start
// and is of maximum size len.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (len > (ft_strlen(s) - start))
		sub = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else if (start >= ft_strlen(s))
		sub = (char *)malloc(sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ft_bzero(sub, len);
		return (sub);
	}
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
