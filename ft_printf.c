/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:34 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/31 17:50:55 by dmontema         ###   ########.fr       */
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
	int args;

	args = ft_countArgs(format);
	if (!args)
	{
		args = ft_strlen(format);
		ft_putstr_fd((char *) format, 1);
	}

	return (args);
}

int main() {
	// printf("%d\n", ft_printf("%c%s%p%d%i%u%x%X%%"));
	// printf("%d\n", ft_printf("Hello, my name is %s and I am %d years old. :)\n"));
	int out = ft_printf("Hello, World!\n");
	int out1 = ft_printf("H");
	printf("\n%d %d\n", out, out1);
	return 0;
}