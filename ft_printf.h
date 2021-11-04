/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:30 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/04 20:47:47 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	<stdarg.h>
# include	<limits.h>
# include	"libft/libft.h"

int ft_printf(const char *, ...);
int ft_putnbr_int(int nbr);
int	ft_putnbr_base(unsigned long nbr, char *set, unsigned base);
int	ft_putchar(char c);
int ft_putstr(char *str);
int	selectConvSpec(char **format, va_list *args);
