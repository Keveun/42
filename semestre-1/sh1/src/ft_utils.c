/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:18:46 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/13 19:54:13 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_ishere(char c, char *s)
{
	return ((c == '/') || !ft_strncmp("./", s, 2) || !ft_strncmp("../", s, 2));
}

char	*ft_str_tolower(char *s)
{
	char	*begin;

	begin = s;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		++s;
	}
	return (begin);
}

char	**ft_initpwd(char **pwd, int n)
{
	char	**s;

	s = pwd;
	while (n--)
		pwd[n] = 0;
	return (s);
}

int		ft_count_tabelem(char **tab)
{
	int		n;

	if (!tab)
		return (0);
	n = 0;
	while (*tab++)
		++n;
	return (n);
}
