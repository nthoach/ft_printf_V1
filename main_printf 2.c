/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf 2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:30 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/02 14:41:57 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *s = "ABC";
	char *s1 = "xyz123";
	int	np;

	np = printf("[This is a test string %%:%15.d:%5c:%-20p:%-5.3x:%-#12X:%-15.10u]\n", 357, 'X', s, 255, 255, UINT32_MAX);
	printf("%d\n", np);
	np = ft_printf("[This is a test string %%:%15.d:%5c:%-20p:%-5.3x:%-#12X:%-15.10u]\n", 357, 'X', s, 255, 255, UINT32_MAX);
	ft_printf("%d\n", np);
	// printf("%%5%s\n", "Hello");
	// ft_printf("%%5%s\n\n", "Hello");
	// printf(":\001\002\007\v\010\f\r:\n");
	// ft_printf(":\001\002\007\v\010\f\r:\n\n");
	// printf("%u%%\n", 0);
	// ft_printf("%u%%\n\n", 0);
	
	// char	s[5] = "OK!";
	// char	s1[5] = "~";
	// int		np = 0;
	
	// np = printf("%c:\n",'\t');
	// printf("%i:\n", np);
	
	// np = ft_printf("%c:\n",'\t');
	// printf("%i:\n", np);

	// np = printf("%d:\n",100);
	// printf("%i:\n", np);
	
	// np = ft_printf("%d:\n",100);
	// printf("%i:\n", np);
	
	// np = printf("%s:%d:%s\n", s, 100, s1);
	// printf("%i:\n", np);
	// np = ft_printf("%s:%d:%s\n", s, 100, s1);
	// printf("%i:\n", np);
	
	// np = printf("%p:%p:\n", s, s1);
	// printf("%i:\n", np);
	// np = ft_printf("%p:%p:\n", s, s1);;
	// printf("%i:\n", np);
	
	np = ft_printf("Printing a string:%42c:%s:%sxX:%p:%-15p:%d:%i:%u:%1.8x:%-2.X:%%:\n",'\t', s,"", s, s1, -2147483647, INT32_MAX, UINT32_MAX, 14, UINT32_MAX);
	ft_printf("%d\n", np);
	np = printf("Printing a string:%42c:%s:%sxX:%p:%-15p:%d:%i:%u:%1.8x:%-2.X:%%:\n",'\t', s,"", s, s1, -2147483647, INT32_MAX, UINT32_MAX, 14, UINT32_MAX);
	printf("%d\n", np);
	system ("leaks a.out");
	return (0);
}
