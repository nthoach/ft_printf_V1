/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:58 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/02 14:56:53 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* print_c:
rules:
// Test cases:
// printf("[%%]\n");					[%]					
// printf("[%2%]\n");					[ %]
// printf("[%-2%]\n");					[% ]
// printf("[%02%]\n");					[0%]
// printf("[%-02%]\n");					[% ]
*/

int	ft_putxstr(char *s, int len)
{
	write(1, s, len);
	return (len);
}

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	else
	{
		while (i < n)
		{
			write(1, &c, 1);
			i++;
		}
	}
	return (n);
}

int	print_c(char c, t_formats formats)
{
	int	n_blank;
	int	np;

	np = 0;
	n_blank = formats.width - 1;
	if (formats.minus == 1)
	{
		np += ft_putnchar(c, 1);
		np += ft_putnchar(' ', n_blank);
	}
	else
	{
		if (formats.zero == 1)
			np += ft_putnchar('0', n_blank);
		else if (formats.zero == 0)
			np += ft_putnchar(' ', n_blank);
		np += ft_putnchar(c, 1);
	}
	return (np);
}
