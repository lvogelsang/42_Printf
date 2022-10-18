/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:43:51 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/18 14:00:39 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
	int	hash;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	width;
	int	type;
}		t_format;

# define SPECIFIERS	"cspdiuxX%"

char		*ft_hexstr(t_format format, unsigned int x);
char		*ft_hex_itoa(unsigned int x, char *hex_base);
char		*ft_itoa(int n);
char		*ft_numstr_signed(t_format format, int n);
char		*ft_ptrstr(size_t ptr);
char		*ft_ptr_itoa(size_t ptr);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_unsigned_itoa(unsigned int u);

int			ft_atoi(const char *str);
int			ft_digitcount(int n);
int			ft_format(char *str, va_list args);
int			ft_format_specifications(char *str, va_list args);
int			ft_hex_digitcount(unsigned int x);
int			ft_isdigit(int c);
int			ft_printf(const char *str, ...);
int			ft_print_c(t_format format, int c);
int			ft_print_d_i(t_format format, int n);
int			ft_print_p(t_format format, size_t ptr);
int			ft_print_pct(void);
int			ft_print_s(t_format format, char *s);
int			ft_print_type(t_format format, va_list args);
int			ft_print_u(t_format format, unsigned int u);
int			ft_print_x(t_format format, unsigned int x);
int			ft_ptr_digitcount(size_t ptr);
int			ft_unsigned_digitcount(unsigned int u);

size_t		ft_strlen(const char *s);

t_format	ft_format_default(void);
t_format	ft_format_flags(char *str, t_format format);
t_format	ft_format_width(char *str, t_format format);

void		ft_default_adjustment(t_format format, char *str);
void		ft_format_adjustment(t_format format, char *str);
void		ft_hexstr_help(t_format format, char *hex_str, unsigned int x);
void		*ft_memset(void *b, int c, size_t len);
void		ft_minus_adjustment(t_format format, char *str);
void		ft_numstr_help(t_format format, char *num_str, int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_zero_adjustment(t_format format, char *str);

/*
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
*/
#endif
