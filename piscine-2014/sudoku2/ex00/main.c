/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talmazov <talmazov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:43:31 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 23:29:45 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_is_valide(char *str);
int		**ft_make_grid(char **grid);
int		*ft_initline(int **grid);
int		*ft_initcolumn(int **grid);
int		**ft_initblock(int **grid);
int		*ft_emptycell(int **grid);
int		**possible(int *gridline, int *gridcol, int **gridblock, int *emptycel);
int		solve(int ***check, int **data, int **grid, int *count);

void	aff_sudoku(int ***check, int **data_possible, int **grid)
{
	int i;
	int count[3];
	int **count2;

	if (!solve(check, data_possible, grid, &count2) && count2[0][0] == 1)
	{
		count[0] = 0;
		count[2] = 1;
		while (count[0] < 9)
		{
			count[1] = 0;
			while (count[1] < 9)
			{
				ft_putchar('0' + grid[count[0]][count[1]]);
				if (count[2] != 9)
					ft_putchar(' ');
				count[2]++;
				count[1]++;
			}
			ft_putchar('\n');
			count[0]++;
		}
	}
	else
		ft_putstr("Erreur\n");
}

int		test_valide(char **argv)
{
	int count[2];

	count[0] = 1;
	count[1] = 0;
	while (argv[count[0]])
	{
		if (!ft_is_valide(argv[count[0]]))
			return (0);
		count[1]++;
		count[0]++;
	}
	return (1);
}

int		check_input(int argc, char **argv)
{
	if (argc != 10 || !test_valide(argv))
	{
		ft_putstr("Erreur\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		**grid;
	int		*gridline;
	int		*gridcolumn;
	int		**gridblock;
	int		*emptycell;
	int		**data_possible;
	int		***check;

	if (!check_input(argc, argv))
		return (0);
	grid = ft_make_grid(argv);
	gridline = ft_initline(grid);
	gridcolumn = ft_initcolumn(grid);
	gridblock = ft_initblock(grid);
	emptycell = ft_emptycell(grid);
	data_possible = possible(gridline, gridcolumn, gridblock, emptycell);
	check = malloc(sizeof(int **) * 3);
	check[0] = &gridline;
	check[1] = &gridcolumn;
	check[2] = gridblock;
	aff_sudoku(check, data_possible, grid);
	return (1);
}
