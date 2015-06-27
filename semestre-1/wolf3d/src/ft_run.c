/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:10:26 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 15:26:04 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_loop(t_mlx *mx)
{
	mlx_put_image_to_window(mx->mlx, mx->win, mx->img, 0, 0);
}

void			ft_display(t_mlx *mx, t_map *map, t_vars *v)
{
	int		x;

	x = -1;
	while (++x < mx->width)
	{
		ft_raystart(v, x, mx->width);
		ft_next_moove(v, map);
		ft_dist(mx, v);
		if (mx->b & 6)
		{
			ft_texture_x(&mx->map, &mx->v);
			ft_floor_casting(v);
		}
		ft_draw(mx, x);
	}
	if (mx->b & 8)
		ft_minimap(mx, map, v);
	ft_loop(mx);
}
