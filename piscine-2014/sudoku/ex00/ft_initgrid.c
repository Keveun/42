/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 23:29:53 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 08:32:24 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_initline(int **grid)
{
	int		*linevalue;
	int		i;
	int		j;

	linevalue = malloc(sizeof(int) * 9);
	i = 0;
	while (i < 9)
	{
		linevalue[i] = 0;
		j = 0;
		while (j < 9)
		{
			if (grid[i][j])
				linevalue[i] += 1 << grid[i][j];
			j++;
		}
		i++;
	}
	return (linevalue);
}

int		*ft_initcolumn(int **grid)
{
	int		*columnvalue;
	int		i;
	int		j;		

	columnvalue = malloc(sizeof(int) * 9);
	i = 0;
	while (i < 9)
	{
		columnvalue[i] = 0;
		j = 0;
		while (j < 9)
		{
			if (grid[j][i])
				columnvalue[i] += 1 << grid[j][i];
			j++;
		}
		i++;
	}
	return (columnvalue);
}

void	ft_initblocksub(int k, int **grid, int **blockvalue, int _i, int _j)
{
	int i;
	int j;

	i = _i;
	while (i < _i + 3)
	{
		j = _j;
		while (j < _j + 3)
		{
			if (grid[i][j])
				blockvalue[k / 3][k % 3] += 1 << grid[i][j];
			j++;
		}
		i++;
	}
}

int		**ft_initblock(int **grid)
{
	int		**blockvalue;
	int		k;
	int		_i;
	int		_j;

	blockvalue = malloc(sizeof(int *) * 3);
	k = 0;
	while (k < 9)
	{
		_i = ((k) ? (k / 3) * 3 : 0);
		_j = (k % 3) * 3;
		if (!(k % 3))
			blockvalue[k / 3] = malloc(sizeof(int) * 3);
		blockvalue[k / 3][k % 3] = 0;
		ft_initblocksub(k, grid, blockvalue, _i, _j);
		k++;
	}
	return (blockvalue);
}

int		*ft_emptycell(int **grid)
{
	int		*emptycell;
	int		i;
	int		j;
	int		k;

	emptycell = malloc(sizeof(int) * 70);
	i = 0;
	k = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (!grid[i][j])
			{
				emptycell[k] = 0;
				emptycell[k] = i * 9 + j;
				k++;
			}
			j++;
		}
		i++;
	}
	emptycell[k] = -1;
	return (emptycell);
}
