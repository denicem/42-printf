/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:44:17 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/05 00:47:37 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"ft_printf.h"

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

int	ft_putnbr_base(unsigned long nbr, char *set, unsigned base, int addr)
{
	int	res;

	res = 0;
	if (addr)
	{
		res += write(1, "0x", 2);
		addr = 0;
	}
	if (nbr >= base)
		res += ft_putnbr_base(nbr / base, set, base, addr);
	res += write(1, set + (nbr % base), 1);
	return (res);
}
