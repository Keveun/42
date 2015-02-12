/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:08:17 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/06 22:46:20 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_iso1(t_p *p, t_point *point, t_mlx *mx, t_point *max)
{
	int		x;
	int		y;
	int		z;

	x = (point->x - max->x / 2) * mx->zoom + mx->x;
	y = (point->y - (max->y - mx->empty) / 2) * mx->zoom + mx->y;
	z = (point->z * mx->zoom * mx->zoomz) / 7;
	p->x1 = ((sqrt(2) / 2.0) * (x - y));
	p->x1 += WIDTH / 2;
	p->y1 = ((1.5 / sqrt(6)) * (x + y) - sqrt(2.0 / 3.0) * z);
	p->y1 += HEIGHT / 2;
}

static void		ft_iso2(t_p *p, t_point *point, t_mlx *mx, t_point *max)
{
	int		x;
	int		y;
	int		z;

	x = (point->x - max->x / 2) * mx->zoom + mx->x;
	y = (point->y - (max->y - mx->empty) / 2) * mx->zoom + mx->y;
	z = (point->z * mx->zoom * mx->zoomz) / 7;
	p->x2 = ((sqrt(2) / 2.0) * (x - y));
	p->x2 += (WIDTH / 2);
	p->y2 = ((1.5 / sqrt(6)) * (x + y) - sqrt(2.0 / 3.0) * z);
	p->y2 += HEIGHT / 2;
}

static void		ft_trait(int i, int j, t_mlx *mx, t_point *max)
{
	t_p			p;
	t_point		point;
	t_point		**map;

	map = mx->map;
	point.x = map[i][j].x;
	point.y = map[i][j].y;
	point.z = map[i][j].z;
	ft_iso1(&p, &point, mx, max);
	if (map[i + 1] && j < map[i + 1][0].len)
	{
		point.x = map[i + 1][j].x;
		point.y = map[i + 1][j].y;
		point.z = map[i + 1][j].z;
		ft_iso2(&p, &point, mx, max);
		ft_draw(&p, mx, map[i][j].z, point.z);
	}
	if (j + 1 < (map[i][0]).len)
	{
		point.x = map[i][j + 1].x;
		point.y = map[i][j + 1].y;
		point.z = map[i][j + 1].z;
		ft_iso2(&p, &point, mx, max);
		ft_draw(&p, mx, map[i][j].z, point.z);
	}
}

static void		ft_putstring(t_mlx *mx)
{
	char	*str;
	char	*var;

	mlx_string_put(mx->mlx, mx->win, 8, 18, 0xffffff, \
			"Hide/Display text: \"option\"");
	var = ft_itoa(mx->zoom);
	str = ft_strjoin("Modify Zoom: \"-+\" numpad, Value: ", var);
	free(var);
	mlx_string_put(mx->mlx, mx->win, 8, 36, 0xffffff, str);
	free(str);
	var = ft_itoa((mx->zoomz * mx->zoom) / 7);
	str = ft_strjoin("Modify Zoom Z: \"-+\", Value: ", var);
	free(var);
	mlx_string_put(mx->mlx, mx->win, 8, 54, 0xffffff, str);
	free(str);
	var = ft_itoa(mx->color);
	str = ft_strjoin("Modify Background color: \"12\", Value: 0x", var);
	free(var);
	mlx_string_put(mx->mlx, mx->win, 8, 72, 0xffffff, str);
	free(str);
	mlx_string_put(mx->mlx, mx->win, 8, 90, 0xffffff, "Screenshot: \"F5\"");
	mlx_string_put(mx->mlx, mx->win, 8, 108, 0xffffff, "Exit: \"Escap\"");
}

void			ft_loop(t_mlx *mx)
{
	int			i;
	int			j;
	t_point		**map;

	ft_fill_img(mx, mx->color);
	map = mx->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < (map[i][0]).len)
			ft_trait(i, j, mx, &mx->max);
	}
	mlx_put_image_to_window(mx->mlx, mx->win, mx->img, 0, 0);
	if (mx->text)
		ft_putstring(mx);
}
