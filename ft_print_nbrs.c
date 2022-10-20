/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:43:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/20 09:13:13 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print function for the conversion types 'd' and 'i'. These types consider 
// the '+', ' ', '-', & '0' flags as well as width and
// precision specifications.

#include <stdio.h>
int	ft_print_d_i(t_format format, int n)
{
	char	*num_str;
	int	i;
	int	len;

	num_str = ft_numstr_d_i(format, n);
	if (num_str == NULL)
		return (0);
	if (format.dot)
		format.zero = 0;
	i = ft_strlen(num_str);
	if (format.width > i)
	{
		len = format.width;
		ft_numstr_help(format, num_str, n);
	}
	else
	{
		len = i;
		ft_putstr_fd(num_str, 1);
	}
	free (num_str);
	return (len);
}

char	*ft_numstr_d_i(t_format format, int n)
{
	char	*numstr_sign;
	char	*numstr_format;

	numstr_sign = ft_numstr_sign(format, n);
	if (numstr_sign == NULL)
		return (NULL);
	if (format.dot)
	{
		numstr_format = ft_numstr_precision(format, numstr_sign, n);
	}
	// Strdup and subsequently freeing the original string could cause issues.
	else
	{
		numstr_format = ft_strdup(numstr_sign);
	}
	free (numstr_sign);
	if (numstr_format == NULL)
		return (NULL);
	return (numstr_format);
}

char	*ft_numstr_sign(t_format format, int n)
{
	char	*sign;
	char	*temp;
	char	*numstr;

	if ((format.plus || format.space) && n >= 0)
	{
		if (format.plus)
			sign = "+";
		else if (format.space)
			sign = " ";
		temp = ft_itoa(n);
		if (temp == NULL)
			return (NULL);
		numstr = ft_strjoin(sign, temp);
		free (temp);
	}
	else
		numstr = ft_itoa(n);
	if (numstr == NULL)
		return (NULL);
	return (numstr);
}

char	*ft_numstr_precision(t_format format, char *num_str, int n)
{
	char	*numstr_format;

	if (format.precision == 0 && n == 0)
	{
		numstr_format = (char *)malloc(sizeof(char));
		if (numstr_format == NULL)
			return (NULL);
		numstr_format[0] = '\0';
	//	printf("%s\n", numstr_format);
	}
	else if ((format.precision > (int)ft_strlen(num_str))
		|| ((format.plus || format.space || (n < 0))
		&& (format.precision == (int)ft_strlen(num_str))))
	{
//		printf("%s\n", num_str);
		numstr_format = ft_numstr_precision2(format, num_str, n);
//		printf("%s\n", numstr_format);
	}
	else
	{
		numstr_format = ft_strdup(num_str);
	}
	if (numstr_format == NULL)
		return (NULL);
//	free (num_str);
//	printf("%s\n", numstr_format);
	return (numstr_format);
}

char	*ft_numstr_precision2(t_format format, char *num_str, int n)
{
	int	x;
	char	*zero;
	char	*numstr_format;
	
	x = 0;
	if (format.plus || format.space || (n < 0))
		x = 1;
	zero = ft_precision_zero(format, num_str, n, x);
	if (zero == NULL)
		return (NULL);
	numstr_format = ft_strjoin(zero, num_str + x);
	free (zero);
	if (numstr_format == NULL)
		return (NULL);
	return (numstr_format);
}

char	*ft_precision_zero(t_format format, char *num_str, int n, int x)
{
	int	count;
	char	*zero;
	int	i;

	count = format.precision - ft_strlen(num_str);
	zero = (char *)malloc((count + x) * sizeof(char));
	if (zero == NULL)
		return (NULL);
//	zero = ""; 
	i = 0;
	if (format.plus || format.space || (n < 0))
	{
		zero[0] = num_str[0];
		i++;
	}
	while (i < (count + x * 2))
	{
		zero[i] = '0';
		i++;
	}
	zero[i] = '\0';
//	printf("%s\n", zero);
	return (zero);
}
/*
int	ft_numstr_precision(t_format format, char *num_str, int n)
{
	int		x;
	size_t	count;
	char	*copy;
	int		len;

	if (format.precision == 0)
	{
		num_str[0] = '\0';
	}
	if ((format.precision > (int)ft_strlen(num_str))
		|| ((format.plus || format.space || (n < 0))
			&& (format.precision == (int)ft_strlen(num_str))))
	{
		x = 0;
		count = format.precision - ft_strlen(num_str);
		if (format.plus || format.space || (n < 0))
			x = 1;
		copy = ft_strdup(num_str + x);
		if (copy == NULL)
			return (0);
		ft_memset(num_str + x, '0', count + x);
		num_str[count + 2 * x] = '\0';
		len = ft_strlen(num_str) + ft_strlen(copy);
		ft_strlcat(num_str, copy, len + 1);
		free (copy);
	}
	return (ft_strlen(num_str));
}
*/
void	ft_numstr_help(t_format format, char *num_str, int n)
{
	int	x;

	x = 0;
	if (format.zero && !(format.minus)
		&& (format.plus || format.space || (n < 0)))
	{
		ft_putchar_fd(num_str[x], 1);
		x++;
		format.width--;
	}
	ft_format_adjustment(format, &num_str[x]);
}/*
int	ft_print_d_i(t_format format, int n)
{
	char	*num_str;
	int		i;
	int		len;

	num_str = ft_numstr_signed(format, n);
	if (num_str == NULL)
		return (0);
	if (format.dot)
	{
		format.zero = 0;
		i = ft_numstr_precision(format, num_str, n);
	}
	else
		i = ft_strlen(num_str);
	if (format.width > i)
	{
		len = format.width;
		ft_numstr_help(format, num_str, n);
	}
	else
	{
		len = i;
		ft_putstr_fd(num_str, 1);
	}
	free (num_str);
	return (len);
}

char	*ft_numstr_signed(t_format format, int n)
{
	char	*sign;
	char	*temp;
	char	*numstr;

	if ((format.plus || format.space) && n >= 0)
	{
		if (format.plus)
			sign = "+";
		else if (format.space)
			sign = " ";
		temp = ft_itoa(n);
		numstr = ft_strjoin(sign, temp);
		free (temp);
	}
	else
		numstr = ft_itoa(n);
	if (numstr == NULL)
		return (NULL);
	return (numstr);
}

int	ft_numstr_precision(t_format format, char *num_str, int n)
{
	int		x;
	size_t	count;
	char	*copy;
	int		len;

	if (format.precision == 0)
	{
		num_str[0] = '\0';
	}
	if ((format.precision > (int)ft_strlen(num_str))
		|| ((format.plus || format.space || (n < 0))
			&& (format.precision == (int)ft_strlen(num_str))))
	{
		x = 0;
		count = format.precision - ft_strlen(num_str);
		if (format.plus || format.space || (n < 0))
			x = 1;
		copy = ft_strdup(num_str + x);
		if (copy == NULL)
			return (0);
		ft_memset(num_str + x, '0', count + x);
		num_str[count + 2 * x] = '\0';
		len = ft_strlen(num_str) + ft_strlen(copy);
		ft_strlcat(num_str, copy, len + 1);
		free (copy);
	}
	return (ft_strlen(num_str));
}

void	ft_numstr_help(t_format format, char *num_str, int n)
{
	int	x;

	x = 0;
	if (format.zero && !(format.minus)
		&& (format.plus || format.space || (n < 0)))
	{
		ft_putchar_fd(num_str[x], 1);
		x++;
		format.width--;
	}
	ft_format_adjustment(format, &num_str[x]);
}*/
