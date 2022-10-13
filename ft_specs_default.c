/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:13:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/10/13 14:54:05 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Creation of a structure that can store all the specifications that
// need to be applied when printing.

// '#' => Specifies that the value should be printed in alternate form
// (for x and X conversions).

// ' ' => Specifies that a blank should be placed before a positive number
// in signed format. This flag is ignored if the '+' flag exists 
// (for d and i conversions).

// '+' => Specifies that there should always be a sign placed before a
// number in signed format (for d and i conversions).

// '-' => Specifies left adjustment of the output.

// '0' => Specifies that zero-padding should be used rather than 
// blank-padding for numeric types. A '-' overrides a '0' if both are used.

t_specs	ft_specs_default(void)
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
