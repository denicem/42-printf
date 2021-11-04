/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:48:18 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/05 00:50:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"ft_printf.h"

# include	<stdio.h>

int main() {
	// test for countArgs
	// printf("%d\n", ft_printf("%c%s%p%d%i%u%x%X%%")); 
	// printf("%d\n", ft_printf("Hello, my name is %s and I am %d years old. :)\n"));

	// test for printing strings and charcters without any arguments and result variable
	// int out = ft_printf("Hello, World!\n");
	// int out1 = ft_printf("H");
	// int out = printf("Hello, World!\n");
	// int out1 = printf("%d", 234);
	// printf("\n%d %d\n", out, out1);
	// ft_printf("HAPPY HALLOWEEN!!\n");

	//test for printing int values only (and result variable)
	// int outInt =  ft_printf("%d%d", 42, 24);
	// printf("\n%d\n", outInt);

	// test for printing strings in combination with arguments (%d, %i, %s, %c, %%) and comparing it with og printf
	// int out = ft_printf("Hello, my name is %s and I am %d years old. :)\n%%\n%c%i\n", "Denice", 25, 'E', 1);
	// int out1 = printf("Hello, my name is %s and I am %d years old. :)\n%%\n%c%i\n", "Denice", 25, 'E', 1);
	// ft_printf("%d | %d\n", out, out1);

	//test for printing pointer address
	int x = 10;
	int out1 = ft_printf("%p\n", &x);
	int out2 = printf("%p\n", &x);
	ft_printf("%d | %d", out1, out2);

	// int out = ft_printf("Hallo, %s.\nHappy Halloween%c\n", "Svenja", '!');
	// int out1 = ft_printf("%d%i %X %x %u\n%d%%\n", 42, 24, 674, 1234, -23445, 100);
	// ft_printf("%d, %d\n", out, out1);
	// out = ft_printf("Hallo, %s.\nHappy Halloween%c\n", "Svenja", '!');
	// out1 = ft_printf("%d%i %X %x %u\n%d%%\n", 42, 24, 674, 1234, -23445, 100);
	// ft_printf("%d, %d\n", out, out1);

	return (0);
}