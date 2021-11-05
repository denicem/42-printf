/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:07:33 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/05 03:19:11 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	selectConvSpec(char **format, va_list *args)
{
	int	res;

	res = 0;
	if (**format == '%')
		res += ft_putchar('%');
	else if (**format == 'c')
		res += ft_putchar(va_arg(*args, int));
	else if (**format == 's')
		res += ft_putstr(va_arg(*args, char *));
	else if (**format == 'd' || **format == 'i')
		res += ft_putnbr_int(va_arg(*args, int));
	else if (**format == 'u')
		res += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789", 10, 0);
	else if (**format == 'x')
		res += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef", 16, 0);
	else if (**format == 'X')
		res += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF", 16, 0);
	else if (**format == 'p')
		res += ft_putaddr(va_arg(*args, void *));
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
	va_end(args);
	return (res);
}
