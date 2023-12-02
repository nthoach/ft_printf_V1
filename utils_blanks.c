/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_blanks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:47:55 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/02 14:42:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_precision(t_formats formats, int no_digit)
{
	int	np;
	int	n_blank;

	np = 0;
	n_blank = formats.precision - no_digit;
	np += ft_putnchar('0', n_blank);
	return (np);
}

int	print_width(t_formats formats, int len_total, char c)
{
	int	np;
	int	n_blank;

	np = 0;
	n_blank = formats.width - len_total;
	np += ft_putnchar(c, n_blank);
	return (np);
}

void	ft_putnbr(long n, int *p_np)
{
	char	c;
	long	nbr;

	nbr = n;
	if (n < 0)
		nbr = -n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, p_np);
	c = nbr % 10 + '0';
	*p_np += ft_putnchar(c, 1);
}
