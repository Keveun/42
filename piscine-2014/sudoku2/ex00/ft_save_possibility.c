/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_possibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talmazov <talmazov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 05:33:49 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 19:46:20 by talmazov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	possibl_s1(int *values, int *emptycell, int **data_ok)
{
	data_ok[values[4]] = malloc(sizeof(int) * 10);
	values[0] = emptycell[values[4]] / 9;
	values[1] = emptycell[values[4]] % 9;
	values[5] = values[0] / 3;
	values[6] = values[1] / 3;
	data_ok[values[4]][0] = emptycell[values[4]];
	values[3] = 1;
	values[2] = 1;
	values[7] = 0;
}

void	possibl_s2(int *values, int *gridcol, int **gridblock, int **data_ok)
{
	if (!(gridcol[values[1]] & values[7]))
	{
		if (!(gridblock[values[5]][values[6]] & values[7]))
		{
			data_ok[values[4]][values[3]] = values[2];
			values[3]++;
		}
	}
}

int		**possible(int *gridline, int *gridcol, int **gridblock, int *emptycel)
{
	int values[8];
	int	**data_ok;

	data_ok = malloc(sizeof(int *) * 70);
	values[0] = 0;
	values[4] = 0;
	while (emptycel[values[4]] != -1)
	{
		possibl_s1(values, emptycel, data_ok);
		while (values[2] < 10)
		{
			values[7] = 1 << values[2];
			if (!(gridline[values[0]] & values[7]))
			{
				possibl_s2(values, gridcol, gridblock, data_ok);
			}
			data_ok[values[4]][values[3]] = -1;
			values[2]++;
		}
		values[0]++;
		values[4]++;
	}
	data_ok[values[4]] = malloc(sizeof(int) * 1);
	data_ok[values[4]][0] = -1;
	return (data_ok);
}
