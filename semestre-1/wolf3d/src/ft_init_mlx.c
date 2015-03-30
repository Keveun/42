/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:06:07 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/15 18:26:34 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_set_tdata(t_mlx *mx)
{
	char	*img;
	int		i;

	img = mx->data;
	i = -1;
	while (++i < mx->height)
		mx->tdata[i] = img + i * mx->width * 4;
}

int				ft_init_mlx(t_mlx *mx)
{
	int		width;

	if (!(mx->mlx = mlx_init()))
		return (1);
	width = WIDTH;
	mx->win = mlx_new_window(mx->mlx, WIDTH, HEIGHT, NAME);
	mx->img = mlx_new_image(mx->mlx, WIDTH, HEIGHT);
	mx->bpp = 24;
	mx->endian = 1;
	mx->height = HEIGHT;
	mx->width = WIDTH;
	mx->top = 0;
	mx->bottom = 0;
	mx->left = 0;
	mx->right = 0;
	mx->screen = 0;
	mx->b = 0;
	mx->data = mlx_get_data_addr(mx->img, &mx->bpp, &width, &mx->endian);
	ft_set_tdata(mx);
	return (0);
}
