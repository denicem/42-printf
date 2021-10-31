/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:34 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/31 20:04:46 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

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
	{
		count_args = ft_strlen(format);
		ft_putstr_fd((char *) format, 1);
	}
	else
	{
		va_start(args, format);
		int i = 0;
		while (i < count_args)
		{
			int val = va_arg(args, int);
			char *s = ft_itoa(val);
			ft_putstr_fd(s, 1);
			i++;
		}
	}

	return (count_args);
}

int main() {
	// printf("%d\n", ft_printf("%c%s%p%d%i%u%x%X%%"));
	// printf("%d\n", ft_printf("Hello, my name is %s and I am %d years old. :)\n"));
	// int out = ft_printf("Hello, World!\n");
	// int out1 = ft_printf("H");
	// int out = printf("Hello, World!\n");
	// int out1 = printf("%d", 234);
	// printf("\n%d %d\n", out, out1);

	int outInt =  ft_printf("%d%d", 42, 24);
	printf("\n%d\n", outInt);
	// printf("%s\n", ft_itoa(42));
	return 0;
}