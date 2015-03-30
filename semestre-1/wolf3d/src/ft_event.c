/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:17:47 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 15:35:11 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define TOP 126
#define BOTTOM 125
#define LEFT 123
#define RIGHT 124
#define ESCAPE 53
#define ONE 83
#define TWO 84
#define THREE 85
#define FOUR 86
#define SCREEN 96

int			expose_hook(t_mlx *mx)
{
	ft_loop(mx);
	return (0);
}

int			key_press_hook(int keycode, t_mlx *mx)
{
	if (keycode == ESCAPE)
		exit (0);
	if (keycode == TOP)
		mx->top = 1;
	if (keycode == BOTTOM)
		mx->bottom = 1;
	if (keycode == LEFT)
		mx->left = 1;
	if (keycode == RIGHT)
		mx->right = 1;
	if (keycode == SCREEN)
		mx->screen = 1;
	return (0);
}

int			key_release_hook(int keycode, t_mlx *mx)
{
	if (keycode == ESCAPE)
		exit (0);
	if (keycode == ONE)
		mx->b ^= 1;
	if (keycode == TWO)
		mx->b ^= 2;
	if (keycode == THREE)
		mx->b ^= 4;
	if (keycode == FOUR)
		mx->b ^= 8;
	if (keycode == SCREEN)
		mx->screen = 0;
	if (keycode == TOP)
		mx->top = 0;
	if (keycode == BOTTOM)
		mx->bottom = 0;
	if (keycode == LEFT)
		mx->left = 0;
	if (keycode == RIGHT)
		mx->right = 0;
	if (keycode == ONE || keycode == TWO ||
		keycode == THREE || keycode == FOUR)
		ft_display(mx, &mx->map, &mx->v);
	return (0);
}

int			key_loop_hook(t_mlx *mx)
{
	if (mx->screen || mx->top || mx->bottom || mx->right || mx->left)
	{
		if (mx->screen)
			ft_tofile(mx->data);
		if (mx->top)
			ft_top(&mx->v, &mx->map);
		if (mx->bottom)
			ft_bottom(&mx->v, &mx->map);
		if (mx->left)
			ft_left(&mx->v);
		if (mx->right)
			ft_right(&mx->v);
		ft_display(mx, &mx->map, &mx->v);
	}
	return (0);
}
