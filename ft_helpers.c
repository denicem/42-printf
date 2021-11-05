/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:02:38 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/05 22:30:19 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	byte_size;
	size_t	i;

	byte_size = count * size;
	res = malloc(byte_size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < byte_size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			res = (char *) s + i;
			break ;
		}
		i++;
	}
	if (s[i] == (char) c)
		res = (char *) s + i;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	res = (char *) malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
