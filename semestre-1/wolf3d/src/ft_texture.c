/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:10:26 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/30 17:07:30 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_texture_x(t_map *map, t_vars *v)
{
	int		id;
	t_img	*img;

	id = map->data[v->map.x][v->map.y] - TEXTURE;
	img = (map->img + id);
	if (v->side)
		v->wall.x = v->raypos.x + ((v->map.y - v->raypos.y + \
		((1 - v->step.y) >> 1)) / v->raydir.y) * v->raydir.x;
	else
		v->wall.x = v->raypos.y + ((v->map.x - v->raypos.x + \
		((1 - v->step.x) >> 1)) / v->raydir.x) * v->raydir.y;
	v->wall.x -= floor(v->wall.x);
	v->tex.x = (int)(v->wall.x * (double)img->width);
	v->tex.x = (v->tex.x < 0) ? 0 : v->tex.x;
	if ((!v->side && v->raydir.x > 0) ||
		(v->side && v->raydir.y < 0))
		v->tex.x = img->width - v->tex.x - 1;
}

void		ft_apply_texture(t_map *map, t_vars *v, int height, int y)
{
	int		ratio;
	int		id;
	t_img	*img;

	id = map->data[v->map.x][v->map.y] - TEXTURE;
	img = map->img + id;
	ratio = y * 256 - height * 128 + v->lineheight * 128;
	v->tex.y = ((ratio * img->height) / v->lineheight) >> 8;
	v->tex.y = (v->tex.y < 0) ? 0 : v->tex.y;
	v->color[0] = img->data[v->tex.y][v->tex.x * 3];
	v->color[1] = img->data[v->tex.y][v->tex.x * 3 + 1];
	v->color[2] = img->data[v->tex.y][v->tex.x * 3 + 2];
	if (v->side)
	{
		v->color[0] = (v->color[0] >> 1) & 0x7f;
		v->color[1] = (v->color[1] >> 1) & 0x7f;
		v->color[2] = (v->color[2] >> 1) & 0x7f;
	}
}

void		ft_set_sky(t_mlx *mx, t_img *sky, int x, int y)
{
	int		index;
	double	dir;
	int		dx;

	if (mx->v.dir.y < 0.0)
		dir = mx->v.adir.x;
	else
		dir = -mx->v.adir.x;
	dir /= 6.31;
	dx = ((int)(dir * sky->width) + x) % sky->width;
	dx = (dx < 0) ? sky->width + dx : dx;
	index = (y * mx->width * 4) + x * 4;
	mx->data[index] = sky->data[y][dx * 3 + 2];
	mx->data[index + 1] = sky->data[y][dx * 3 + 1];
	mx->data[index + 2] = sky->data[y][dx * 3];
}

void		ft_set_floor(t_mlx *mx, t_img *dfloor, int x, int y)
{
	double		weight;
	t_dcoord	currentfloor;
	t_coord		floortex;

	weight = (mx->height / (2.0 * y - mx->height)) / mx->v.correctwalldist;
	currentfloor.x = weight * mx->v.floor.x + (1.0 - weight) * mx->v.pos.x;
	currentfloor.y = weight * mx->v.floor.y + (1.0 - weight) * mx->v.pos.y;
	floortex.x = ((int)(currentfloor.x * dfloor->width) % dfloor->width);
	floortex.y = ((int)(currentfloor.y * dfloor->height) % dfloor->height);
	if (floortex.x < 0 || floortex.y < 0)
		return ;
	mx->tdata[y][x * 4] = dfloor->data[floortex.y][floortex.x * 3 + 2];
	mx->tdata[y][x * 4 + 1] = dfloor->data[floortex.y][floortex.x * 3 + 1];
	mx->tdata[y][x * 4 + 2] = dfloor->data[floortex.y][floortex.x * 3];
}
