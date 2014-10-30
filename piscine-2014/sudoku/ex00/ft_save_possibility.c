/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_possibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 05:33:49 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 11:21:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	**possible(int *gridline, int *gridcolumn, int **gridblock, int *emptycell)
{
	int	i;
	int	j;
	int k;
	int l;
	int _i;
	int	_j;
	int	m;
	int	**data_possible;
	int	value;

	data_possible = malloc(sizeof(int *) * 70);
	i = 0;
	value = 0;
	m = 0;
	while (emptycell[m] != -1)
	{
		data_possible[m] = malloc(sizeof(int) * 10);
		i = ((emptycell[m]) ? emptycell[m] / 9 : 0);
		j = ((emptycell[m]) ? emptycell[m] % 9 : 0);
		_i = ((emptycell[m]) ? i / 3 : 0);
		_j = ((emptycell[m]) ? j / 3 : 0);
		data_possible[m][0] = emptycell[m];
		l = 1;
		k = 1;
		value = 0;
		while (k < 10)
		{
			value = 1 << k;
			if(!(gridline[i] & value) && !(gridcolumn[j] & value) && !(gridblock[_i][_j] & value))
			{
				data_possible[m][l] = k;
				l++;
			}
			data_possible[m][l] = -1;
			k++;
		}
		i++;
		m++;
	}
	data_possible[m] = malloc(sizeof(int) * 1);
	data_possible[m][0] = -1;
	//printf("%d", data_possible[m][0]);
	return (data_possible);
}
