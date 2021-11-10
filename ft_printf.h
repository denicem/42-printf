/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:35:30 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/10 17:51:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define	FT_PRINTF_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>
# include	<limits.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_int(int nbr, int flag);
int		ft_putnbr_base(unsigned long nbr, char *set, unsigned int base, int f);
int		ft_putaddr(void *addr);

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

enum	e_flag {
	noflag,
	space,
	plus,
	hash
};

#	endif