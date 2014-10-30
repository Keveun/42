/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/04 12:03:13 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/04 20:32:56 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*src_copy;

	i = 0;
	while (src[i])
		i++;
	src_copy = (char*)malloc(sizeof(*src_copy) * (i + 1));
	if (src_copy == NULL)
		return (NULL);
	j = 0;
	while (src[j])
	{
		src_copy[j] = src[j];
		j++;
	}
	src_copy[j] = '\0';
	return (src_copy);
}
