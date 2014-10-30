/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 08:41:15 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 23:33:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	copy_grid(int **grid, int **copy);

int		solve_condition(int *c, int ***check)
{
	if (!(check[0][0][c[0]] & c[5]) &&
		!(check[1][0][c[1]] & c[5]) &&
		!(check[2][c[2]][c[3]] & c[5]))
		return (1);
	return (0);
}

void	solve_sub(int *c, int ***check, int **grid, int **data)
{
	grid[c[0]][c[1]] = data[0][c[4]];
	check[0][0][c[0]] += c[5];
	check[1][0][c[1]] += c[5];
	check[2][c[2]][c[3]] += c[5];
}

void	solve_sub2(int ***check, int *c)
{
	check[0][0][c[0]] -= c[5];
	check[1][0][c[1]] -= c[5];
	check[2][c[2]][c[3]] -= c[5];
}

int		checksolve(int **count, int **data, int **copy, int **grid)
{
	copy_grid(grid, copy);
	count = malloc(sizeof(int *) * 2);
	count = copy;
	count[0][0] += 1;
	return (count[0][0] - 1);
}

int		solve(int ***check, int **data, int **grid, int **count)
{
	int	c[6];
	int	**copy;

	if (data[0][0] == -1)
		return (checksolve(count, data, copy, grid));
	c[0] = data[0][0] / 9;
	c[1] = data[0][0] % 9;
	c[2] = c[0] / 3;
	c[3] = c[1] / 3;
	c[4] = 1;
	while (data[0][c[4]] != -1)
	{
		c[5] = 1 << data[0][c[4]];
		if (solve_condition(c, check))
		{
			solve_sub(c, check, grid, data);
			if (solve(check, data + 1, grid, count))
				return (1);
			else
				solve_sub2(check, c);
		}
		c[4]++;
	}
	return (0);
}
