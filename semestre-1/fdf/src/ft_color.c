/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:58:22 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/29 20:17:49 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_img(t_mlx *mx, int color)
{
	int				total;
	int				i;
	unsigned char	rgb[3];

	total = WIDTH * HEIGHT * 4;
	rgb[2] = (((color * 3000) >> 16) & 0xFF);
	rgb[1] = (((color * 30) >> 8) & 0xFF);
	rgb[0] = ((color) & 0xFF);
	i = 0;
	while (i < total)
	{
		mx->data[i] = rgb[0];
		mx->data[i + 1] = rgb[1];
		mx->data[i + 2] = rgb[2];
		mx->data[i + 3] = 1;
		i += 4;
	}
}

void	ft_set_colors(t_mlx *mx, int x, int y, int color)
{
	unsigned char	*rgb;
	int				value;
	int				coord;

	value = mlx_get_color_value(mx->mlx, color);
	rgb = (unsigned char*)&value;
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	coord = (x * 4) + (y * mx->sizeline);
	mx->data[coord] = rgb[0];
	mx->data[coord + 1] = rgb[1];
	mx->data[coord + 2] = rgb[2];
	mx->data[coord + 3] = rgb[3];
}
