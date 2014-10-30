/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/05 10:45:42 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/05 16:30:08 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *str, int n)
{
	int		i;
	int		j;
	char	*ptr;

	j = n;
	while (str[j] && str[j] != 32 && str[j] != 9 && str[j] != 10)
		j++;
	ptr = (char *)malloc(sizeof(char *) * (j + 1));
	i = n;
	while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 10)
	{
		ptr[i - n] = str[i];
		i++;
	}
	ptr[i - n] = '\0';
	return (ptr);
}

int		ft_count(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9 || str[i] == 10)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	split = (char **)malloc(sizeof(char **) * ft_count(str) + 1);
	i = 0;
	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[j] && (str[j] != 32 && str[j] != 9 && str[j] != 10))
		{
			split[k] = ft_strndup(str, j);
			while (str[j] && (str[j] != 32 && str[j] != 9 && str[j] != 10))
				j++;
			k++;
		}
		i++;
		j++;
	}
	split[k] = 0;
	return (split);
}
