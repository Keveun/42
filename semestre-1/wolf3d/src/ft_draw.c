/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:10:26 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 18:27:33 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_draw_sky(t_mlx *mx, int x, int y, int pixel)
{
	if (mx->b & 1)
		ft_set_sky(mx, &mx->map.sky, x, y);
	else
		ft_put_pixel(&mx->v, mx->data, pixel, SKY);
}

static void		ft_draw_wall(t_mlx *mx, int y, int pixel)
{
	if (mx->map.data[mx->v.map.x][mx->v.map.y] > 2 && mx->b & 2)
		ft_apply_texture(&mx->map, &mx->v, mx->height, y);
	else
		ft_set_color(&mx->v);
	ft_put_pixel(&mx->v, mx->data, pixel, WALL);
}

static void		ft_draw_floor(t_mlx *mx, int x, int y, int pixel)
{
	if (mx->b & 4)
		ft_set_floor(mx, &mx->map.floor, x, y);
	else
		ft_put_pixel(&mx->v, mx->data, pixel, CEILING);
}

void			ft_draw(t_mlx *mx, int x)
{
	int		y;
	int		pixel;

	if (mx->v.drawend < 0)
		return ;
	y = -1;
	while (++y < HEIGHT)
	{
		pixel = (y * mx->width * 4) + x * 4;
		if (y < mx->v.drawstart)
			ft_draw_sky(mx, x, y, pixel);
		else if (y < mx->v.drawend)
			ft_draw_wall(mx, y, pixel);
		else
			ft_draw_floor(mx, x, y, pixel);
	}
}
