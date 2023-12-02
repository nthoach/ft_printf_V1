/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:22:56 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/02 11:59:25 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	(1) printing signed integer numbers with %d and %i
	[%#d] [%#i] has no effective of # because there is no
	alternative ways to present d or i
	(2) range is singed integer typeof(int)
	(3) Blanks and justify flags printed if width > len(itoa(d_i))
	(4) width < len: no justify, print the whole length
	(5) if .prcn, with precision > len, [000ddd] printed
	(6) [+000dd] [-00dd] [ 00dd], [ ] is only when no -(left justified), 
	and for positive number only
	(7) precision < len -> ignore precison, print whole len
	(8) prescision = 0 && di = 0, no print
	(9) if having "w.p" (having precision), ignore flag "0"
	(10) "+"" will disable " ", and "-" will disable "0"
	exmaples:
	left_justified with "-":
	[(+/-/ )(prc-000)(123)(   )] with "-" left-justified
	right_justified and .precision
	[(  )((+/-/ )(prc-000)(123))] right-justified if width > len
	[(+/-/ )(123)] right-justified if width < len
	right_justified && no .precision and width > len
	no "0": (  )(+- )(123)
	yes "0": (+- )(000-width)(123)
*/

static int	print_di1(t_formats formats, int n, int no_digit, int len_total)
{
	int	np;

	np = 0;
	np += print_width(formats, len_total, ' ');
	np += print_sign(formats, n);
	np += print_precision(formats, no_digit);
	if (!(n == 0 && formats.dot == 1 && formats.precision == 0))
		ft_putnbr((long)n, &np);
	return (np);
}

static int	print_di2(t_formats formats, int n, int len_total)
{
	int	np;

	np = 0;
	np += print_sign(formats, n);
	np += print_width(formats, len_total, '0');
	ft_putnbr(n, &np);
	return (np);
}

static int	print_di3(t_formats formats, int n, int len_total)
{
	int	np;

	np = 0;
	np += print_width(formats, len_total, ' ');
	np += print_sign(formats, n);
	ft_putnbr(n, &np);
	return (np);
}

static int	print_di4(t_formats formats, int n, int no_digit, int len_total)
{
	int	np;

	np = 0;
	np += print_sign(formats, n);
	np += print_precision(formats, no_digit);
	if (!(n == 0 && formats.dot == 1 && formats.precision == 0))
		ft_putnbr(n, &np);
	np += print_width(formats, len_total, ' ');
	return (np);
}

int	print_d_i(int n, t_formats formats)
{
	int	np;
	int	no_digit;
	int	len_total;

	np = 0;
	no_digit = len_int(n);
	len_total = totalize_len(n, no_digit, &formats);
	if (formats.precision == 0 && formats.dot == 1 && n == 0)
		len_total--;
	if (formats.minus == 0 && formats.dot == 1)
		np += print_di1(formats, n, no_digit, len_total);
	if (formats.minus == 0 && formats.dot == 0)
	{
		if (formats.zero == 1)
			np += print_di2(formats, n, len_total);
		else
			np += print_di3(formats, n, len_total);
	}
	if (formats.minus == 1)
		np += print_di4(formats, n, no_digit, len_total);
	return (np);
}
