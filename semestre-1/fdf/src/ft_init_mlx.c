/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 19:36:34 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/30 22:21:47 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_zoom(int x, int y)
{
	int		i;

	i = 0;
	while (WIDTH > sqrt((x * i) * (x * i) + (y * i) * (y * i)))
		++i;
	return ((i) ? i : 1);
}

static void		ft_maxlen(t_point **map, t_point *max)
{
	int		i;

	i = -1;
	max->x = 0;
	max->y = 0;
	while (map[++i])
	{
		if (map[i][0].len > max->x)
			max->x = map[i][0].len;
	}
	max->y = i;
}

static double	ft_min_max(t_mlx *mx)
{
	int			i;
	int			j;
	t_point		**map;

	i = -1;
	map = mx->map;
	mx->minz = map[0][0].z;
	mx->maxz = map[0][0].z;
	while (map[++i])
	{
		j = -1;
		if (!map[i][0].len)
			++mx->empty;
		while (++j < map[i][0].len)
		{
			if (map[i][j].z > mx->maxz)
				mx->maxz = map[i][j].z;
			if (map[i][j].z < mx->minz)
				mx->minz = map[i][j].z;
		}
	}
	return (ft_ratio(ft_gap(mx->maxz, mx->minz)));
}

void			ft_init_mlx(t_mlx *mx)
{
	int		endian;

	if (!(mx->mlx = mlx_init()))
		ft_error("mlx_init Fail\n");
	mx->sizeline = WIDTH;
	mx->win = mlx_new_window(mx->mlx, WIDTH, HEIGHT, NAME);
	mx->img = mlx_new_image(mx->mlx, WIDTH, HEIGHT);
	mx->bpp = 24;
	endian = 1;
	mx->data = mlx_get_data_addr(mx->img, &mx->bpp, &mx->sizeline, &endian);
	ft_maxlen(mx->map, &mx->max);
	mx->zoom = ft_zoom(mx->max.x, mx->max.y);
	mx->empty = 0;
	mx->ratio = ft_min_max(mx);
	mx->zoomz = 1;
	mx->x = 1;
	mx->y = 1;
	mx->color = 0;
	mx->text = 1;
}
