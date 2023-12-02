/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:25:32 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/02 12:47:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 formats:
 dot:
 1) (0x/0X)(prc-000)(123)(width-blank) (left)
 2) (width-blank)(0x/0X)(prc-000)(123) (right)
 no dot:
 3) (width_blank)(0x/0X)(123) (right)
 4) (0x/0X)(width-zero)(123) (right)
*/

int	print_x(unsigned int x, t_formats formats, char c)
{
	int	np;
	int	len_hex;
	int	len_total;

	np = 0;
	len_hex = len_uint(x, formats, 16);
	len_total = len_hex;
	if (formats.precision > len_total)
		len_total = formats.precision;
	if (!(formats.sharp == 1 && x == 0))
		len_total += 2 * formats.sharp;
	if ((formats.minus == 0 && formats.dot == 1)
		|| (formats.minus == 0 && formats.dot == 0 && formats.zero == 0))
		np += print_width(formats, len_total, ' ');
	np += print_0x(formats, c, x);
	if (formats.minus == 0 && formats.dot == 0 && formats.zero == 1)
		np += print_width(formats, len_total, '0');
	if (formats.dot == 1)
		np += print_precision (formats, len_hex);
	print_hex(x, c, formats, &np);
	if (formats.minus == 1)
		np += print_width(formats, len_total, ' ');
	return (np);
}
