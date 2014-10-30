/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:43:31 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 11:58:11 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str);
int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_is_valide(char *str);
int		**ft_make_grid(char **grid);
int		*ft_initline(int **grid);
int		*ft_initcolumn(int **grid);
int		**ft_initblock(int **grid);
int		*ft_emptycell(int **grid);
int		**possible(int *gridline, int *gridcolumn, int **gridblock, int *emptycell);
int		solve(int ***check, int **data, int **grid);


int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		**grid;
	int		*gridinit;
	int		*gridline;
	int		*gridcolumn;
	int		**gridblock;
	int		*emptycell;
	int		**data_possible;
	int		***check;

	if (argc == 10)
	{
		i = 1;
		j = 0;
		while (argv[i])
		{
			while (argv[i][j])
			{
				if (!ft_is_valide(argv[i]))
				{
					ft_putstr("Erreur\n");
					return (0);
				}
				j++;
			}
			i++;
		}
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
		if (solve(check, data_possible, grid))
		{
			i = 0;
			while (i < 9)
			{
				j = 0;
				while (j < 9)
				{
					printf("%d ", grid[i][j]);
					j++;
				}
				printf("\n");
				i++;
			}
		}
		else
		{
			ft_putstr("Erreur\n");
		}
	}
	else
		ft_putstr("Erreur\n");
	return (0);
}
