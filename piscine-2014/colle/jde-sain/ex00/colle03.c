/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 15:17:27 by kperreau          #+#    #+#             */
/*   Updated: 2014/08/30 17:49:40 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	check_x_y(int x, int y, int x_loop, int y_loop)
{
	if (x_loop == 1 && (y_loop == y || y_loop == 1))
	{
		ft_putchar('A');
	}
	else
	{
		if ((y_loop == 1 && x_loop == x) || (y_loop == y && x_loop == x))
		{
			ft_putchar('C');
		}
		else
		{
			if (y_loop == 1 || y_loop == y || x_loop == x || x_loop == 1)
			{
				ft_putchar('B');
			}
			else
			{
				ft_putchar(' ');
			}
		}
	}
}

void	colle(int x, int y)
{
	int	x_loop;
	int y_loop;

	if (x > 0 || y > 0)
	{
		x_loop = 1;
		y_loop = 1;
		while (y_loop <= y)
		{
			while (x_loop <= x)
			{
				check_x_y(x, y, x_loop, y_loop);
				x_loop++;
			}
			ft_putchar('\n');
			x_loop = 1;
			y_loop++;
		}
	}
}
