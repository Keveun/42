/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 17:56:19 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 23:22:03 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != -1)
		count++;
	return (count);
}

void		copy_grid(int **grid, int **copy)
{
	int		i;
	int		j;

	copy = malloc(sizeof(int *) * 9);
	i = 0;
	j = 0;
	while (i < 9)
	{
		copy[i] = malloc(sizeof(int) * 9);
		while (j < 9)
		{
			copy[i][j] = grid[i][j];
			j++;
		}
		i++;
		j = 0;
	}
}
