/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/04 20:34:31 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/04 22:42:22 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	count;
	int	*tab;

	count = max - min;
	tab = (int*)malloc(sizeof(*tab) * count);
	if (max > min && count)
	{
		i = 0;
		while (i < count)
		{
			tab[i] = i + min;
			i++;
		}
	}
	else
		tab = NULL;
	return (tab);
}
