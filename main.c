/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:48:18 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/10 17:47:12 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

#include	<stdio.h>

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

	// test for printing int values only (and result variable)
	// int outInt =  ft_printf("%d%d", 42, 24);
	// printf("\n%d\n", outInt);

	// test for printing strings in combination with arguments (%d, %i, %s, %c, %%) and comparing it with og printf
	// int out = ft_printf("Hello, my name is %s and I am %d years old. :)\n%%\n%c%i\n", "Denice", 25, 'E', 1);
	// int out1 = printf("Hello, my name is %s and I am %d years old. :)\n%%\n%c%i\n", "Denice", 25, 'E', 1);
	// ft_printf("%d | %d\n", out, out1);

	// int out = ft_printf("Hallo, %s.\nHappy Halloween%c\n", "Svenja", '!');
	// int out1 = ft_printf("%d%i %X %x %u\n%d%%\n", 42, 24, 674, 1234, -23445, 100);
	// ft_printf("%d, %d\n", out, out1);
	// out = printf("Hallo, %s.\nHappy Halloween%c\n", "Svenja", '!');
	// out1 = printf("%d%i %X %x %u\n%d%%\n", 42, 24, 674, 1234, -23445, 100);
	// ft_printf("%d, %d\n", out, out1);

	// test for printing pointer address
	// int x = 10;
	// int out1 = ft_printf("%p\n", &x);
	// int out2 = printf("%p\n", &x);
	// ft_printf("%d | %d", out1, out2);

	// test if string is NULL
	// ft_printf("%d\n", ft_printf(" NULL %s NULL ", NULL));

	// test for LONG numbers
	// printf("LONGMAX: %u\nLONG_MIN: %u\nULONG_MAX: %u\n922333...: %u\n\n", LONG_MAX, LONG_MIN, ULONG_MAX, 9223372036854775807LL);
	// printf("\n");
	// ft_printf("LONG_MAX: %u\nLONG_MIN: %u\nULONG_MAX: %u\n922333...: %u\n", LONG_MAX, LONG_MIN, ULONG_MAX, 9223372036854775807LL);

	// test for long addresses
	// printf("%p %p\n", LONG_MIN, LONG_MAX);
	// ft_printf("%p %p\n", LONG_MIN, LONG_MAX);

	// tests from tri-tester - still not clear if test is valid - upd: should be valid.
	// ft_printf("| % 1s|\n", "");
	// ft_printf("|% 1s |\n", "");
	// printf("| % 1s|\n", "");
	// printf("|% 1s |\n", "");

	// tests for checking return value of printf with flags;
	// ft_printf("\nMY: %d\n", ft_printf("% d", 42));
	// ft_printf("\nOG: %d\n", printf("% d", 42));
	// ft_printf("\nMY: %d\n", ft_printf("%+d", 42));
	// ft_printf("\nOG: %d\n", printf("%+d", 42));
	// ft_printf("\nMY: %d\n", ft_printf("%#x", 42));
	// ft_printf("\nOG: %d\n", printf("%#x", 42));
	// ft_printf("\nMY: %d\n", ft_printf("%#X", 42));
	// ft_printf("\nOG: %d\n", printf("%#X", 42));

	// // general test for printf
	// int nbr = 42;
	// int to_uns_nbr = -25;
	// int to_hex = 823451;
	// char *str = "Hello 42";

	// printf("OWN PRINTF\n");
	// ft_printf("H");
	// ft_printf("ello\n");
	// ft_printf("%%\n");
	// ft_printf("%c\n", nbr);
	// ft_printf("%s\n", str);
	// ft_printf("%d\n", nbr);
	// ft_printf("%i\n", to_uns_nbr);
	// ft_printf("%u\n", to_uns_nbr);
	// ft_printf("%x\n", to_hex);
	// ft_printf("%X\n", to_hex);
	// ft_printf("%p\n", &str);

	// printf("----------\n");

	// printf("OG PRINTF\n");
	// printf("H");
	// printf("ello\n");
	// printf("%%\n");
	// printf("%c\n", nbr);
	// printf("%s\n", str);
	// printf("%d\n", nbr);
	// printf("%i\n", to_uns_nbr);
	// printf("%u\n", to_uns_nbr);
	// printf("%x\n", to_hex);
	// printf("%X\n", to_hex);
	// printf("%p\n", &str);

	// printf("----------\n");

	// // testing return value from printf
	// printf("RETURN VALUE from printf:\n");
	// printf("MY: %d\n", ft_printf("%d", nbr));
	// printf("\nOG: %d\n", printf("%d",nbr));
	// printf("\nMY: %d\n", ft_printf("%s", str));
	// printf("\nOG: %d\n", printf("%s", str));
	// printf("\nMY: %d\n", ft_printf("%p", &str));
	// printf("\nOG: %d\n", printf("%p", &str));

	// printf("----------\n");

	// // test for bonus p2
	// ft_printf("% d\n", nbr);
	// printf("% d\n", nbr);
	// ft_printf("%+d\n", nbr);
	// printf("%+d\n", nbr);
	// ft_printf("%#x\n", to_hex);
	// printf("%#x\n", to_hex);
	// ft_printf("%#X\n", to_hex);
	// printf("%#X\n", to_hex);

	ft_printf("%p %p\n", 0, 0);
	printf("%p %p\n", 0, 0);
	ft_printf("%#x\n", 0);
	printf("%#x\n", 0);

	// system("leaks a.out");
	return (0);
}