/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:39:13 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/28 21:17:17 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_ratiobegin(t_mlx *mx, int z1)
{
	int			begin;
	double		ratiobegin;

	begin = ft_gap(mx->minz, z1);
	ratiobegin = begin * mx->ratio;
	return (-ratiobegin);
}

static double	ft_grad(t_mlx *mx, int z1, int z2, double dist)
{
	double		ratioz;
	double		grad;

	ratioz = ft_gap(z1, z2) / dist;
	grad = (mx->ratio * ratioz);
	return (-grad);
}

void			ft_draw(t_p *p, t_mlx *mx, int z1, int z2)
{
	double		dist;
	t_dpoint	dp;
	double		color;
	double		grad;

	dp.dx = p->x2 - p->x1;
	dp.dy = p->y2 - p->y1;
	dist = sqrt((dp.dx * dp.dx) + (dp.dy * dp.dy));
	dp.dx /= dist;
	dp.dy /= dist;
	dp.x = p->x1;
	dp.y = p->y1;
	grad = ft_grad(mx, z1, z2, dist);
	color = ft_ratiobegin(mx, z1);
	while (dist-- >= 0)
	{
		if (color + grad > 0 && color + grad < 0xffffff)
			color += grad;
		ft_set_colors(mx, (int)dp.x, (int)dp.y, (int)color);
		dp.x += dp.dx;
		dp.y += dp.dy;
	}
}
