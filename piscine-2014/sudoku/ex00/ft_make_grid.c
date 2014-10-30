/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 17:04:15 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 03:37:57 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_make_grid(char **grid)
{
	int		**tab;
	int 	i;
	int		j;
	int 	k;
	
	tab = malloc(sizeof(int *) * 9);
	i = 1;
	j = 0;
	k = 0;
	while (grid[i])
	{
		tab[i - 1] = malloc(sizeof(int) * 9);
		while (grid[i][j])
		{
			tab[i - 1][j] = ((grid[i][j] != '.') ? (grid[i][j] - 48) : 0);
			j++;
		}
		i++;
		j = 0;
	}
	return (tab);
}
