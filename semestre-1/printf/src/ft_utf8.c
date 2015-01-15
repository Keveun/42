/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:10:16 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 00:24:26 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_utfclen(int c)
{
	if (ft_binlen(c) <= 7)
		return (1);
	else if (ft_binlen(c) <= 11)
		return (2);
	else if (ft_binlen(c) <= 16)
		return (3);
	else if (ft_binlen(c) <= 21)
		return (4);
	return (-1);
}

int		ft_utfnlen(wchar_t *s, int n)
{
	int		len;
	int		temp;
	int		mem;

	len = 0;
	while (*s && len <= n)
	{
		mem = len;
		temp = ft_utfclen(*s++);
		len += temp;
	}
	return ((len != n) ? mem : n);
}

int		ft_utflen(wchar_t *s)
{
	int		len;
	int		temp;

	len = 0;
	while (*s)
	{
		temp = ft_utfclen(*s++);
		if (temp < 0)
			return (-1);
		len += temp;
	}
	return (len);
}

int		ft_to_utf8(int c, int bytes, unsigned char *mask)
{
	int		i;
	int		ft_or[3];

	if (bytes < 2)
	{
		mask[0] = (unsigned char)c;
		return (0);
	}
	ft_or[0] = 0xC0;
	ft_or[1] = 0xE0;
	ft_or[2] = 0xF0;
	i = 0;
	while (i < bytes)
	{
		mask[i] = 0;
		if (!i)
			mask[i] = (c >> (8 * (bytes - 1) - 2 * (bytes - 1))) \
				| ft_or[bytes - 2];
		else
			mask[i] = ((c >> (8 * (bytes - (i + 1)) \
				 - 2 * (bytes - (i + 1)))) & 0x3F) | 0x80;
		++i;
	}
	return (0);
}
