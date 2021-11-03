/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:34 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/03 21:15:25 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *set, unsigned base);

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
		//TODO: add a func to select to select a specifier conversion. 
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
				//usage of ft_putnbr_base works with every base including unsinged integer
				else if (*format == 'x')
				{
					count_args += ft_putnbr_base(va_arg(args, long unsigned), "0123456789abcdef", 16); 
					format++;
				}
				else if (*format == 'X')
				{
					count_args += ft_putnbr_base(va_arg(args, long unsigned), "0123456789ABCDEF", 16);
					format++;
				}
				else if (*format == 'o')
				{
					count_args += ft_putnbr_base(va_arg(args, long unsigned), "01234567", 8);
					format++;
				}
				else if (*format == 'b')
				{
					count_args += ft_putnbr_base(va_arg(args, long unsigned), "01", 2);
					format++;
				}
				else if (*format == 'u')
				{
					count_args += ft_putnbr_base(va_arg(args, long unsigned), "0123456789", 10);
					format++;
				}
				// END usage of ft_putnbr_base works with every base including unsinged integer
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

///////////////////////////////////////////////////////////////////////////////

// PROTOTYPE printing hexadecimal
// void	put_nbrx(long long unsigned nbr) {}

// PROTOTYPE printing unsigned integer
int	ft_putnbr_base(unsigned long nbr, char *set, unsigned base)
{
	unsigned tmp;
	int res;

	res = 0;
	if (nbr >= base)
		res += ft_putnbr_base(nbr / base, set, base);
	tmp = nbr % base;
	res += write(1, set + tmp, 1);
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
	// int x = 10;
	// int out1 = ft_printf("%p\n", &x);
	// printf("\n");
	// int out2 = printf("%p\n", &x);
	// ft_printf("%d | %d", out1, out2);

	// printf("%u\n", INT_MIN);
	// printf("%u\n", INT_MAX);
	// printf("%u\n", INT_MIN +1);
	// printf("%u\n", -1);
	// printf("%u\n", -2);
	// printf("%u\n", -3);
	// printf("%u\n", -4);
	// printf("%u\n", -5);
	// printf("%u\n", -6);
	// int i = ft_putnbr_base(32, "01", 2);
	// printf ("%d\n", i);

	ft_printf("%u\n", -2);

	return 0;
}
