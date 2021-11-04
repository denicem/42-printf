/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:07:33 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/04 21:10:59 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putnbr_int(int nbr)
{
	int	res;

	res = 0;
	if (nbr == INT_MIN)
	{
		res += write(1, "-2", 2);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		res += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		res += ft_putnbr_int(nbr / 10);
	res += ft_putchar(nbr % 10 + 48);
	return (res);
}

int	ft_putnbr_base(unsigned long nbr, char *set, unsigned base)
{
	int	res;

	res = 0;
	if (nbr >= base)
		res += ft_putnbr_base(nbr / base, set, base);
	res += write(1, set + (nbr % base), 1);
	return (res);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int	res;

	if (str == NULL)
		return (0);
	res = 0;
	while (*str)
		res += ft_putchar(*str++);
	return (res);
}

// TODO: from "else if: %u, ..." line too long, assign va_arg in one ul var and then call the funcs
int	selectConvSpec(char **format, va_list *args)
{
	int	res;

	res = 0;
	if (**format == '%')
		res+= (ft_putchar('%'));
	else if (**format == 'c')
		res += (ft_putchar(va_arg(*args, int)));
	else if (**format == 's')
		res += (ft_putstr(va_arg(*args, char *)));
	else if (**format == 'd' || **format == 'i')
		res += (ft_putnbr_int(va_arg(*args, int)));
	else if (**format == 'u')
		res += (ft_putnbr_base(va_arg(*args, unsigned long), "0123456789", 10));
	else if (**format == 'x')
		res += (ft_putnbr_base(va_arg(*args, unsigned long), "0123456789abcdef", 16));
	else if (**format == 'X')
		res += (ft_putnbr_base(va_arg(*args, unsigned long), "0123456789ABCDEF", 16));
	else if (**format == 'p')
	{
		res += ft_putstr("0x");
		res += (ft_putnbr_base(va_arg(*args, unsigned long), "0123456789abcdef", 16));
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			res += selectConvSpec((char **) &format, &args);
		}
		else
			res += ft_putchar(*format);
		format++;
	}
	return (res);
}

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


	return 0;
}