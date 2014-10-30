/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/05 01:33:24 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/05 16:37:07 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	if (!src[0])
		return (dest);
	j = 0;
	while (dest[j])
		j++;
	i = 0;
	while (src[i])
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*concat;
	int		total;

	j = 1;
	total = 0;
	while (argv[j])
	{
		total += ft_strlen(argv[j]) + 1;
		j++;
	}
	concat = (char*)malloc(sizeof(*concat) * total + 1);
	i = 1;
	while (i < argc)
	{
		ft_strcat(concat, argv[i]);
		ft_strcat(concat, "\n");
		i++;
	}
	return (concat);
}
