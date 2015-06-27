/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:15:09 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 15:34:39 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pixel(t_vars *v, char *data, int num, t_type type)
{
	if (type == GROUND)
	{
		data[num] = 255;
		data[num + 1] = 164;
		data[num + 2] = 52;
	}
	else if (type == CEILING)
	{
		data[num] = 182;
		data[num + 1] = 182;
		data[num + 2] = 182;
	}
	else if (type == WALL)
	{
		data[num] = v->color[2];
		data[num + 1] = v->color[1];
		data[num + 2] = v->color[0];
	}
	else
	{
		data[num] = 255;
		data[num + 1] = 192;
		data[num + 2] = 84;
	}
}

void		ft_set_color(t_vars *v)
{
	if (!v->side)
	{
		v->color[0] = 0xff;
		v->color[1] = 0x00;
		v->color[2] = 0x00;
	}
	else
	{
		v->color[0] = 0x00;
		v->color[1] = 0x00;
		v->color[2] = 0xff;
	}
	if ((v->pos.x > v->map.x && !v->side) ||
		(v->pos.y < v->map.y && v->side))
	{
		v->color[0] >>= 1;
		v->color[1] >>= 1;
		v->color[2] >>= 1;
	}
}
