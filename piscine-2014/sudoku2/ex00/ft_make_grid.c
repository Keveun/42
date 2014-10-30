/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talmazov <talmazov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 17:04:15 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 20:00:11 by talmazov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_make_grid(char **grid)
{
	int		**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(int *) * 9);
	i = 1;
	j = 0;
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
