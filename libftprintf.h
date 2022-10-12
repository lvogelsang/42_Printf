/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:43:51 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 19:25:30 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_specs
{
	int	hash;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	width;
}		t_specs;

# define SPECIFIERS	"cspdiuxX%"

char	*ft_strchr(const char *s, int c);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_printf(const char *str, ...);
int		ft_print_specs(t_specs specs, va_list args);
int		ft_specs(char *str, va_list args);

t_specs	ft_spec_default(void);
t_specs	ft_specs_flags(char *str, t_specs specs);
t_specs	ft_specs_width(char *str, t_specs specs);

void	ft_putchar_fd(char c, int fd);

#endif
