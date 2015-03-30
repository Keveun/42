/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:06:07 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 18:26:58 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_find_start(t_vars *v, t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->data[i][j] == 1)
			{
				v->pos.x = i;
				v->pos.y = j;
				return (1);
			}
		}
	}
	return (0);
}

int			ft_init_vars(t_vars *v, t_map *map)
{
	v->dir.x = 0;
	v->dir.y = 1;
	v->plane.x = 0.66;
	v->plane.y = 0.0;
	v->movespeed = 0.07;
	v->rotspeed = 0.035;
	v->rotspeedc = cos(v->rotspeed);
	v->rotspeeds = sin(v->rotspeed);
	if (!ft_find_start(v, map))
		return (-1);
	return (0);
}
