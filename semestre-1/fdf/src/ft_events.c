/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 17:19:51 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/28 21:36:38 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				expose_hook(t_mlx *mx)
{
	ft_loop(mx);
	return (0);
}

static void		ft_color(int keycode, t_mlx *mx)
{
	if (keycode == 49)
	{
		if (mx->color - 40 >= 0)
			mx->color -= 40;
		ft_loop(mx);
	}
	else if (keycode == 50)
	{
		if (mx->color + 40 <= 0xffffff)
			mx->color += 40;
		ft_loop(mx);
	}
}

static void		ft_moove(int keycode, t_mlx *mx)
{
	if (keycode == 65362)
	{
		mx->x -= 10;
		mx->y -= 10;
		ft_loop(mx);
	}
	else if (keycode == 65364)
	{
		mx->x += 10;
		mx->y += 10;
		ft_loop(mx);
	}
	else if (keycode == 65361)
	{
		mx->y += 10;
		mx->x -= 10;
		ft_loop(mx);
	}
	else if (keycode == 65363)
	{
		mx->y -= 10;
		mx->x += 10;
		ft_loop(mx);
	}
}

static void		ft_zoom(int keycode, t_mlx *mx)
{
	if (keycode == 61)
	{
		mx->zoomz *= 1.1;
		ft_loop(mx);
	}
	else if (keycode == 45)
	{
		if (mx->zoomz * 0.9 > 0)
			mx->zoomz *= 0.9;
		ft_loop(mx);
	}
	else if (keycode == 65451)
	{
		mx->zoom *= 1.1;
		ft_loop(mx);
	}
	else if (keycode == 65453)
	{
		if (mx->zoom * 0.9 > 1)
			mx->zoom *= 0.9;
		ft_loop(mx);
	}
}

int				key_hook(int keycode, t_mlx *mx)
{
	if (keycode == 65307)
		exit (0);
	else if (keycode == 65406)
	{
		mx->text = !mx->text;
		ft_loop(mx);
	}
	else if (keycode == 65474)
	{
		if (HEIGHT > 30)
		{
			mlx_string_put(mx->mlx, mx->win, 8, HEIGHT - 18, 0xffffff, \
				"Loading...");
			ft_loop(mx);
		}
		ft_tofile(mx->data);
		if (HEIGHT > 30)
			mlx_string_put(mx->mlx, mx->win, 8, HEIGHT - 18, 0xffffff, \
			"Done ! Saved in ./fdf.bmp");
	}
	ft_color(keycode, mx);
	ft_moove(keycode, mx);
	ft_zoom(keycode, mx);
	return (0);
}
