/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:33:33 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 23:44:29 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define LEETLEN "11121211121132124111324211"
#define LEET "48([)3|=6#1_|X1|v|^/0|*(_,)257(_)\\/\\/\\/><7≥"

static int	ft_cleetlen(char c)
{
	if (c >= 'a' && c <= 'z')
		return (LEETLEN[c - 'a'] - '0');
	else if (c >= 'A' && c <= 'Z')
		return (LEETLEN[c - 'A'] - '0');
	return (1);
}

static int	ft_leetlen(char *s)
{
	int		len;

	len = 0;
	while (*s)
		len += ft_cleetlen(*s++);
	return (len);
}

static int	ft_write_g(t_options *opt, char *s)
{
	int		len;

	len = ft_strlen(s);
	len = (opt->precise != -1 && len > opt->precise) ? opt->precise : len;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	write(1, s, len);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len != -1 && len < opt->len) ? opt->len : len;
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

static char	*ft_leet(char *s)
{
	char	*l;
	int		len;
	char	*temp;
	int		j;
	int		begin;

	len = ft_leetlen(s);
	l = (char*)malloc(sizeof(char) * len + 1);
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

int			ft_g(t_options *opt, va_list *ap, int *ret)
{
	char		*s;
	int			value;

	s = NULL;
	if ((s = va_arg(*ap, char *)))
	{
		s = ft_leet(s);
		value = ft_write_g(opt, s);
	}
	else
	{
		s = ft_strdup("(null)");
		value = ft_write_g(opt, s);
		free(s);
	}
	*ret += value;
	return (value);
}
