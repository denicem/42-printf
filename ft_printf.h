/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:30 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/05 00:50:00 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define	FT_PRINTF_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>
# include	<limits.h>

int	ft_printf(const char *format, ...);
int	selectConvSpec(char **format, va_list *args);
int	ft_putnbr_int(int nbr);
int	ft_putnbr_base(unsigned long nbr, char *set, unsigned int base, int addr);
int	ft_putchar(char c);
int	ft_putstr(char *str);

#	endif