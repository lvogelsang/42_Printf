/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:43:51 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 15:01:14 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_specs
{
	int	hash;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	width;
	int	type;
}		t_specs;

# define SPECIFIERS	"cspdiuxX%"

char	*ft_conv_hex(t_specs specs, unsigned int x);
char	*ft_strchr(const char *s, int c);
char	*ft_printf_help(char *str);

int		ft_atoi(const char *str);
int		ft_digitcount(int n);
int		ft_isdigit(int c);
int		ft_printf(const char *str, ...);
int		ft_print_c(t_specs specs, va_list args);
int		ft_print_d_i(t_specs specs, va_list args);
int		ft_print_pct(void);
int		ft_print_s(t_specs specs, va_list args);
int		ft_print_u(t_specs specs, va_list args);
int		ft_print_specs(t_specs specs, va_list args);
int		ft_print_x_p(t_specs specs, va_list args);
int		ft_specs(char *str, va_list args);

size_t	ft_strlen(const char *s);

t_specs	ft_specs_default(void);
t_specs	ft_specs_flags(char *str, t_specs specs);
t_specs	ft_specs_width(char *str, t_specs specs);

void	ft_print_hex(t_specs specs, char *hex_str, int i);
void	ft_print_nbr(t_specs specs, int n, int i);
void	ft_print_pad(t_specs specs, int i, char pad);
void	ft_print_sign(t_specs specs, int neg);
void	ft_print_str(t_specs specs, char *str, int i);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
