/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_specification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:13:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/12 14:43:56 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Creation of a structure that can store all the specifications that
// need to be applied when printing.

t_specs	ft_spec_default(void)
{
	t_specs	specs;

	specs.hash = 0;
	specs.space = 0;
	specs.plus = 0;
	specs.minus = 0;
	specs.zero = 0;
	specs.width = 0;
	specs.type = 0;
	return (specs);
}
