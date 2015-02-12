/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:13:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/12 18:13:14 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t		ft_nbrstr(char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		if (!ft_iswhitespace(*str) && \
			(!n || (n && ft_iswhitespace(*(str - 1)))))
			++n;
		++str;
	}
	return (n);
}

static size_t		ft_strlenc(const char *str)
{
	char	*temp;

	temp = (char *)str;
	while (!ft_iswhitespace(*str) && *str)
		++str;
	return (str - temp);
}

char				**ft_splitword(const char *s)
{
	char	**str;
	char	**temp;
	size_t	n;
	size_t	lenc;

	if (s == NULL)
		return (NULL);
	n = ft_nbrstr((char*)s);
	if ((str = (char**)malloc(sizeof(char*) * n + 1)) == NULL)
		return (NULL);
	temp = str;
	while (n-- > 0)
	{
		while (ft_iswhitespace(*s))
			++s;
		lenc = ft_strlenc(s);
		*str = ft_strsub(s, 0, lenc);
		s += lenc;
		++str;
	}
	*str = '\0';
	return (temp);
}
