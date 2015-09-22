/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:48:07 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/17 17:48:09 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define LEETLEN "11121211121132124111324211"
#define LEET "48([)3|=6#1_|X1|v|^/0|*(_,)257(_)\\/\\/\\/><7="

static int	ft_cleetlen(char c)
{
	if (c >= 'a' && c <= 'z')
		return (LEETLEN[c - 'a'] - '0');
	else if (c >= 'A' && c <= 'Z')
		return (LEETLEN[c - 'A'] - '0');
	return (1);
}

int			ft_leetnlen(char *s, int i)
{
	int		len;
	int		mem;

	len = 0;
	mem = 0;
	while (*s && len <= i)
	{
		mem = len;
		len += ft_cleetlen(*s++);
	}
	return ((len != i) ? mem : i);
}

static int	ft_leetlen(char *s)
{
	int		len;

	len = 0;
	while (*s)
		len += ft_cleetlen(*s++);
	return (len);
}

static int	ft_beginleet(char c)
{
	int		begin;
	int		i;
	int		dist;

	dist = 0;
	if (c >= 'a' && c <= 'z')
		dist = c - 'a';
	else if (c >= 'A' && c <= 'Z')
		dist = c - 'A';
	begin = 0;
	i = 0;
	while (i < dist)
	{
		begin += LEETLEN[i] - '0';
		++i;
	}
	return (begin);
}

char		*ft_leet(char *s)
{
	char	*l;
	int		len;
	char	*temp;
	int		j;
	int		begin;

	l = (char*)malloc(sizeof(char) * ft_leetlen(s) + 1);
	temp = l;
	while (*s)
	{
		if (ft_isalpha(*s))
		{
			begin = ft_beginleet(*s);
			j = -1;
			len = ft_cleetlen(*s);
			while (++j < len)
				*l++ = LEET[begin + j];
		}
		else
			*l++ = *s;
		++s;
	}
	*l = '\0';
	return (temp);
}
