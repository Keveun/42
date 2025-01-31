/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 22:06:04 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/06 20:28:37 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_flag(char *s1, char *s2, int len)
{
	int		i;
	int		j;
	char	*ts2;
	int		flags;

	i = 0;
	ts2 = s2;
	flags = 0;
	while (*s1)
	{
		s2 = ts2;
		j = 0;
		while (*s2 && j < len)
		{
			if (*s1 == *s2++)
				flags |= 1 << i;
			++j;
		}
		++i;
		++s1;
	}
	return (flags);
}

int		ft_len(char *str, int len)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < len)
	{
		if (str[i - 1] != '.' && ft_isdigit(str[i]) && ft_atoi(str + i) > 0)
		{
			n = ft_atoi(str + i);
			i += ft_digitlen(n);
		}
		else
			++i;
	}
	return (n);
}

int		ft_precise(char *str, int len)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < len)
	{
		if (str[i - 1] == '.' && ft_isdigit(str[i]))
		{
			n = ft_atoi(str + i);
			i += ft_digitlen(n);
		}
		else
			++i;
	}
	return (n);
}

int		ft_modif(char *s1, int len)
{
	int		j;
	char	*s2;
	int		modif;

	j = -1;
	s1 += len - 1;
	while (++j < len)
	{
		s2 = FT_MODIF;
		while (*s2)
		{
			if (*s1 == *s2)
			{
				modif = s2 - FT_MODIF;
				if (*s2 == 'l' && *(s1 - 1) == 'l')
					modif = 5;
				else if (*s2 == 'h' && *(s1 - 1) == 'h')
					modif = 6;
				return(modif);
			}
			++s2;
		}
		--s1;
	}
	return (-1);
}
