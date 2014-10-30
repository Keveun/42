/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/04 22:48:40 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/05 01:20:35 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	count;
	int *sub_range;

	count = max - min;
	sub_range = (int*)malloc(sizeof(*sub_range) * count);
	if (max > min && count && sub_range != NULL)
	{
		i = 0;
		while (i < count)
		{
			sub_range[i] = i + min;
			i++;
		}
		*range = sub_range;
		return (count);
	}
	*range = NULL;
	return (0);
}
