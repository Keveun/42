/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 23:19:36 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 15:47:01 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_top(t_vars *v, t_map *map)
{
	if (map->data[(int)(v->pos.x + v->dir.x * (v->moveSpeed + 0.2))]\
		[(int)v->pos.y] <= START)
		v->pos.x += v->dir.x * v->movespeed;
	if (map->data[(int)v->pos.x]\
		[(int)(v->pos.y + v->dir.y * (v->moveSpeed + 0.2))] <= START)
		v->pos.y += v->dir.y * v->movespeed;
}

void		ft_bottom(t_vars *v, t_map *map)
{
	if (map->data[(int)(v->pos.x - v->dir.x * (v->moveSpeed + 0.2))]\
		[(int)v->pos.y] <= START)
		v->pos.x -= v->dir.x * v->movespeed;
	if (map->data[(int)v->pos.x]\
		[(int)(v->pos.y - v->dir.y * (v->moveSpeed + 0.2))] <= START)
		v->pos.y -= v->dir.y * v->movespeed;
}

void		ft_right(t_vars *v)
{
	double	olddirx;
	double	oldplanex;

	olddirx = v->dir.x;
	v->dir.x = v->dir.x * v->rotspeedc - v->dir.y * -v->rotspeeds;
	v->dir.y = olddirx * -v->rotspeeds + v->dir.y * v->rotspeedc;
	oldplanex = v->plane.x;
	v->plane.x = v->plane.x * v->rotspeedc - v->plane.y * -v->rotspeeds;
	v->plane.y = oldplanex * -v->rotspeeds + v->plane.y * v->rotspeedc;
	v->adir.x = (v->dir.x >= -1 && v->dir.x <= 1) ? acos(v->dir.x) : 0;
}

void		ft_left(t_vars *v)
{
	double	olddirx;
	double	oldplanex;

	olddirx = v->dir.x;
	v->dir.x = v->dir.x * v->rotspeedc - v->dir.y * v->rotspeeds;
	v->dir.y = olddirx * v->rotspeeds + v->dir.y * v->rotspeedc;
	oldplanex = v->plane.x;
	v->plane.x = v->plane.x * v->rotspeedc - v->plane.y * v->rotspeeds;
	v->plane.y = oldplanex * v->rotspeeds + v->plane.y * v->rotspeedc;
	v->adir.x = (v->dir.x >= -1 && v->dir.x <= 1) ? acos(v->dir.x) : 0;
}
