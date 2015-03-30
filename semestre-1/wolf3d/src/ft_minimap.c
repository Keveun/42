/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:10:26 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 15:36:44 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_fill_wall(int x, int y, t_mlx *mx, int type)
{
	int		sx;
	int		sy;
	int		coord;

	x *= MINIMAP;
	y *= MINIMAP;
	sx = x + MINIMAP;
	sy = y + MINIMAP;
	while (y < sy)
	{
		while (x < sx)
		{
			coord = y * mx->width * 4 + x * 4;
			mx->data[coord] = 0;
			mx->data[coord + 1] = (type) ? 255 : 0;
			mx->data[coord + 2] = 0;
			++x;
		}
		x = sx - MINIMAP;
		++y;
	}
}

void		ft_minimap(t_mlx *mx, t_map *map, t_vars *v)
{
	int		y;
	int		x;
	int		posx;
	int		posy;

	if (map->height * MINIMAP > mx->height ||
		map->width * MINIMAP > mx->width)
		return ;
	posx = (int)v->pos.x;
	posy = (int)v->pos.y;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] > 1)
				ft_fill_wall(x, y, mx, 0);
			else if (y == posx && x == posy)
				ft_fill_wall(x, y, mx, 1);
			++x;
		}
		++y;
	}
}
