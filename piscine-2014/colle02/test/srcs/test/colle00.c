/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acieux <acieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/31 16:43:07 by acieux            #+#    #+#             */
/*   Updated: 2014/09/14 21:33:56 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_putchar(char c);

void	set_square(char *str, char **square, int index)
{
	int	i;

	square[index] = malloc(sizeof(char) * 6 + 1);
	i = 0;
	while (str[i])
	{
		square[index][i] = str[i];
		i++;
	}	
}

void	which(int *x, int *y, char **square, int index)
{
	if (x[0] == 0 && y[0] == 0)
		ft_putchar(square[index][0]);
	else if (x[0] == (x[1] - 1) && y[0] == 0)
		ft_putchar(square[index][1]);
	else if (x[0] == 0 && y[0] == (y[1] - 1))
		ft_putchar(square[index][2]);
	else if (x[0] == (x[1] - 1) && y[0] == (y[1] - 1))
		ft_putchar(square[index][3]);
	else if (y[0] == 0 || y[0] == (y[1] - 1))
		ft_putchar(square[index][4]);
	else if (x[0] == 0 || x[0] == (x[1] - 1))
		ft_putchar(square[index][5]);
	else
		ft_putchar(' ');
}

void	colle(int xx, int yy, char **square, int index)
{
	int		x[2];
	int		y[2];

	x[1] = xx;
	y[1] = yy;
	if (x[1] <= 0 || y[1] <= 0)
		return ;
	y[0] = 0;
	while (y[0] < y[1])
	{
		x[0] = 0;
		while (x[0] < x[1])
		{
			which(x, y, square, index);
			x[0]++;
		}
		ft_putchar('\n');
		y[0]++;
	}
}

void	loop_square(int x, int y, int i2)
{
	char	**square;
	int		i;

	square = malloc(sizeof(char *) * 5 + 1);
	set_square("/\\\\/**", square, 0);
	set_square("oooo-|", square, 1);
	set_square("AACCBB", square, 2);
	set_square("ACACBB", square, 3);
	set_square("ACCABB", square, 4);
	i = 0;
	while (i < 5)
	{
		if (i2 == i)
			colle(x, y, square, i2);
		i++;
	}
}
