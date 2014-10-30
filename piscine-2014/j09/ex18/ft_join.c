/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 15:18:41 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 15:39:42 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count(char **tab, char *sep)
{
	int	i;
	int j;
	int l;
	int	count;

	i = 0;
	count = 0;
	while (tab[i++])
	{
		j = 0;
		while (tab[i][j++])
			count++;
		l = 0;
		while (sep[l++])
			count++;
	}
	return (count);
}

char	*ft_join(char **tab, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	int		l;

	str = malloc(sizeof(str) * count(tab, sep) + 1);
	i = 0;
	k = 0;
	while (tab[i++])
	{
		j = 0;
		while (tab[i][j])
			str[k++] = tab[i][j++];
		l = 0;
		while (sep[l])
			str[k++] = sep[l++];
	}
	return (str);
}
