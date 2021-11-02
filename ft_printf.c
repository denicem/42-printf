/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:34 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/02 00:31:07 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

// void	ft_putunbr_fd(int n, int fd)
// {
// 	if (n < 0)
// 	{
// 		n = INT_MAX + n;
// 	}
// 	// if (n < 0)
// 	// {
// 	// 	n = -n;
// 	// 	ft_putchar_fd('-', fd);
// 	// }
// 	if (n > 9)
// 		ft_putunbr_fd(n / 10, fd);
// 	ft_putchar_fd(n % 10 + 48, fd);
// }

int	ft_countArgs(const char *format)
{
	int res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
				format++;
			res++;
		}
		format++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int count_args;
	va_list args;

	count_args = ft_countArgs(format);
	if (!count_args)
	// PROTOTYPE print strings and chars, if there are no arguments
	{
		count_args = ft_strlen(format);
		ft_putstr_fd((char *) format, 1);
	}
	// END PROTOTYPE print strings and chars, if there are no arguments
	else
	{
		va_start(args, format);

		// PROTOTYPE: printing arguments (i, d, s, c %%) with characters within
		//TODO: other method for printing of numbers (with ft_putnbr)
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				if ((*format == 'd') || (*format == 'i'))
				{
					int intVal = va_arg(args, int);
					char *s = ft_itoa(intVal);
					ft_putstr_fd(s, 1);
					format++;
					count_args += (int) ft_strlen(s) - 1;
				}
				// else if (*format)
				// {
				// 	int intU = va_arg(args, int);
					
				// }
				else if (*format == 's')
				{
					char *str = va_arg(args, char *);
					ft_putstr_fd(str, 1);
					format++;
					count_args += (int) ft_strlen(str) - 1;
				}
				else if (*format == 'c')
				{
					char c = va_arg(args, int);
					ft_putchar_fd(c, 1);
					format++;
				}
				else if (*format == '%')
				{
					ft_putchar_fd('%', 1),
					format++;
				}
				else if (*format == 'p')
				{
					long long unsigned lluVal = (long long unsigned) va_arg(args, void *);
					int out = printf("0x%llx", lluVal);
					// char *s = ft_itoa(intVal);
					// ft_putstr_fd(s, 1);
					count_args += out;
					format++;
					// count_args += (int) ft_strlen(s) - 1;
				}
				else
					format++;
			}
			else
			{
				ft_putchar_fd(*format, 1);
				count_args++;
				format++;
			}
		}
		// END PROTOTYPE: printing arguments (i, d, s, c %%) with characters within

		// PROTOTYPE: printing int values
		// int i = 0;
		// while (i < count_args)
		// {
		// 	int val = va_arg(args, int);
		// 	char *s = ft_itoa(val);
		// 	ft_putstr_fd(s, 1);
		// 	i++;
		// }
		// END PROTOTYPE: printing int values

	}

	return (count_args);
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
	printf("\n");
	int out2 = printf("%p\n", &x);
	ft_printf("%d | %d", out1, out2);

	// ft_printf("%u", -2);

	return 0;
}