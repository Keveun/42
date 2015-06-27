/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 19:07:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 18:25:49 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_raystart(t_vars *v, int x, int width)
{
	v->camera.x = 2 * x / (double)width - 1;
	v->raypos.x = v->pos.x;
	v->raypos.y = v->pos.y;
	v->raydir.x = v->dir.x + v->plane.x * v->camera.x;
	v->raydir.y = v->dir.y + v->plane.y * v->camera.x;
	v->map.x = (int)v->raypos.x;
	v->map.y = (int)v->raypos.y;
	v->sizewall.x = sqrt(1 + (v->raydir.y * v->raydir.y) / \
		(v->raydir.x * v->raydir.x));
	v->sizewall.y = sqrt(1 + (v->raydir.x * v->raydir.x) / \
		(v->raydir.y * v->raydir.y));
}

static void		ft_hit_wall(t_vars *v, t_map *map)
{
	while (1)
	{
		if (v->distwall.x < v->distwall.y)
		{
			v->distwall.x += v->sizewall.x;
			v->map.x += v->step.x;
			v->side = 0;
		}
		else
		{
			v->distwall.y += v->sizewall.y;
			v->map.y += v->step.y;
			v->side = 1;
		}
		if (map->data[v->map.x][v->map.y] > START)
			break ;
	}
}

void			ft_next_moove(t_vars *v, t_map *map)
{
	if (v->raydir.x < 0)
	{
		v->step.x = -1;
		v->distwall.x = (v->raypos.x - v->map.x) * v->sizewall.x;
	}
	else
	{
		v->step.x = 1;
		v->distwall.x = (v->map.x + 1.0 - v->raypos.x) * v->sizewall.x;
	}
	if (v->raydir.y < 0)
	{
		v->step.y = -1;
		v->distwall.y = (v->raypos.y - v->map.y) * v->sizewall.y;
	}
	else
	{
		v->step.y = 1;
		v->distwall.y = (v->map.y + 1.0 - v->raypos.y) * v->sizewall.y;
	}
	ft_hit_wall(v, map);
}

void			ft_floor_casting(t_vars *v)
{
	v->floor.x = v->map.x;
	v->floor.y = v->map.y;
	if (!v->side)
	{
		if (v->raydir.x > 0)
			v->floor.y += v->wall.x;
		else
		{
			v->floor.x += 1.0;
			v->floor.y += v->wall.x;
		}
	}
	else
	{
		if (v->raydir.y > 0)
			v->floor.x += v->wall.x;
		else
		{
			v->floor.x += v->wall.x;
			v->floor.y += 1.0;
		}
	}
}

void			ft_dist(t_mlx *mx, t_vars *v)
{
	int		lineheight2;
	int		height2;

	if (!v->side)
		v->correctwalldist = fabs((v->map.x - v->raypos.x + \
			((1 - v->step.x) >> 1)) / v->raydir.x);
	else
		v->correctwalldist = fabs((v->map.y - v->raypos.y + \
			((1 - v->step.y) >> 1)) / v->raydir.y);
	v->lineheight = abs((int)(mx->height / v->correctwalldist));
	lineheight2 = v->lineheight >> 1;
	height2 = mx->height >> 1;
	v->drawstart = -lineheight2 + height2;
	if (v->drawstart < 0)
		v->drawstart = 0;
	v->drawend = lineheight2 + height2;
	if (v->drawend >= mx->height)
		v->drawend = mx->height - 1;
}
