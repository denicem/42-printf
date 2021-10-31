/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:34 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/31 17:23:09 by dmontema         ###   ########.fr       */
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

	return (args);
}

int main() {
	// printf("%d\n", ft_printf("%c%s%p%d%i%u%x%X%%"));
	printf("%d\n", ft_printf("Hello, %s!\n"));
	// printf("%%\n");
	return 0;
}