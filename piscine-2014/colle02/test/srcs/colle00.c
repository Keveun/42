/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acieux <acieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/31 16:43:07 by acieux            #+#    #+#             */
/*   Updated: 2014/09/15 15:19:33 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/colle2.h"

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

void	which(int *x, int *y, char **square, char *gen_square)
{
	if (x[0] == 0 && y[0] == 0)
		*gen_square = square[0][0];
	else if (x[0] == (x[1] - 1) && y[0] == 0)
		*gen_square = square[0][1];
	else if (x[0] == 0 && y[0] == (y[1] - 1))
		*gen_square = square[0][2];
	else if (x[0] == (x[1] - 1) && y[0] == (y[1] - 1))
		*gen_square = square[0][3];
	else if (y[0] == 0 || y[0] == (y[1] - 1))
		*gen_square = square[0][4];
	else if (x[0] == 0 || x[0] == (x[1] - 1))
		*gen_square = square[0][5];
	else
		*gen_square = ' ';
}

void	colle(int xx, int yy, char **square, char *gen_square)
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
			which(x, y, square, gen_square++);
			x[0]++;
		}
		*gen_square++ = '\n';
		y[0]++;
	}
}

void	show(int i, int j, int x, int y)
{
	if (j)
	{
		ft_putstr(" || ");
	}
	ft_putstr("[colle-0");
	ft_putchar(i + 48);
	ft_putstr("] [");
	ft_putnbr(x);
	ft_putstr("] [");
	ft_putnbr(y);
	ft_putstr("]");
}

int		loop_square(int x, int y, char *gen_square, char *value)
{
	char	**square;
	int		i;
	int		j;

	square = malloc(sizeof(char *) * 5 + 1);
	i = 0;
	j = 0;
	while (i < 5)
	{
		if (i == 1)
			set_square("/\\\\/**", square, 0);
		else if (i == 0)
			set_square("oooo-|", square, 0);
		else if (i == 2)
			set_square("AACCBB", square, 0);
		else if (i == 3)
			set_square("ACACBB", square, 0);
		else
			set_square("ACCABB", square, 0);
		colle(x, y, square, gen_square);
		if (ft_strcmp(gen_square, value) == 0)
			show(i, j++, x, y);
		i++;
	}
	return (0);
}
