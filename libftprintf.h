/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:43:51 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/11 15:14:42 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		ft_istype(char c);

size_t	ft_check_type(const char *input, va_list args, size_t len);
size_t	ft_printcharacter(const char *input, va_list args, size_t len);
size_t	ft_printstring(const char *input, va_list args, size_t len);

#endif
