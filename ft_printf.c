/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:29:54 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/02 14:57:38 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	print different data-types based on defined formats
*/
static int	print_types(va_list ap, t_formats formats, char **s)
{
	int	np;

	np = 0;
	if (**s == 'c')
		np += print_c(va_arg(ap, int), formats);
	if (**s == 's')
		np += print_s(va_arg(ap, char *), formats);
	if (**s == 'p')
		np += print_p(va_arg(ap, unsigned long), formats);
	if (**s == 'd' || **s == 'i')
		np += print_d_i(va_arg(ap, int), formats);
	if (**s == 'u')
		np += print_u(va_arg(ap, unsigned int), formats);
	if (**s == 'x' || **s == 'X')
		np += print_x(va_arg(ap, unsigned int), formats, **s);
	if (**s == '%')
		np += print_c('%', formats);
	(*s)++;
	return (np);
}

/*
	Get all possible flags for formats of data types
	and save it into formats tructures.
	s --> *s --> **s
	any change in the pointer *s can be saved and updated in s
	"-0." & '# +'
*/
static void	get_flags(t_formats *formats, char **s)
{
	while (ft_strchr("-0# +", **s) != 0)
	{
		if (**s == '-')
			formats->minus = 1;
		if (**s == '0')
			formats->zero = 1;
		if (**s == '#')
			formats->sharp = 1;
		if (**s == ' ')
			formats->space = 1;
		if (**s == '+')
			formats->plus = 1;
		(*s)++;
	}
}

/*
	ascii to integer conversion to get numbers of width or precision
*/
static void	get_width_prcn(int *width, char **s)
{
	while (**s >= '0' && **s <= '9')
	{
		*width = *width * 10 + (**s - '0');
		(*s)++;
	}
}

/*
	printing the data types after %, need to move va_arg
	order:
	1- Reset the formats variable to zeros
	2- write the format flags to formats, 
	*s updated inside each subfunction
	3- write the width number to formats
	4- if having "." -> get precision
	5- recognize data type flags and print the relevant data types
*/
static int	print_options(va_list ap, char **s)
{
	int			np;
	t_formats	formats;

	np = 0;
	ft_memset(&formats, 0, sizeof(t_formats));
	get_flags(&formats, s);
	get_width_prcn(&formats.width, s);
	if (**s == '.')
	{
		formats.dot = 1;
		(*s)++;
		get_width_prcn(&(formats.precision), s);
	}
	if (ft_strchr("cspdiuxX%", (**s)))
		np = print_types(ap, formats, s);
	return (np);
}

/* 
	two cases:
	1-Normal string --> rpint
	2- 
*/

int	ft_printf(const	char *s_in, ...)
{
	char	*s;
	int		np;
	va_list	ap;

	np = 0;
	s = (char *) s_in;
	va_start(ap, s_in);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			np += print_options(ap, &s);
		}
		else
		{
			np += ft_putnchar(*s, 1);
			s++;
		}
	}
	va_end(ap);
	return (np);
}
