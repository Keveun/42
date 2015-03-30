/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:17:47 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/16 22:01:33 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_trait_texture(int fd, t_img *img)
{
	char	buf[5];
	char	*data;
	int		i;

	read(fd, buf, 5);
	img->height = ft_atoi(buf);
	read(fd, buf, 5);
	img->width = ft_atoi(buf);
	if ((data = malloc(sizeof(char) * img->height * img->width * 3)) == NULL)
		return (0);
	read(fd, data, img->height * img->width * 3);
	if ((img->data = malloc(sizeof(char*) * img->height)) == NULL)
		return (0);
	i = -1;
	while (++i < img->height)
		img->data[i] = data + (i * img->width * 3);
	return (1);
}

static int	ft_load_texture(char *path, int value, t_map *map)
{
	int		fd;

	path[9] = value + 48 - 3;
	ft_strcpy(path + 9 + ft_nbrlen(value), ".kp");
	path[13 + ft_nbrlen(value)] = '\0';
	if ((fd = open(path, O_RDONLY)) != -1)
	{
		ft_trait_texture(fd, map->img + value - 3);
		close(fd);
	}
	return ((fd == -1) ? -1 : 0);
}

int			ft_find_textures(t_map *map)
{
	char	path[255];
	char	texture[10];
	int		i;
	int		j;
	int		value;

	ft_bzero(texture, 10);
	ft_strcpy(path, "textures/");
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			value = (int)map->data[i][j];
			if (value > 2 && !texture[value])
			{
				if (ft_load_texture(path, value, map) == -1)
					return (-1);
				texture[value] = 1;
			}
		}
	}
	return (0);
}

int			ft_init_map(t_map *map, char *filename)
{
	int		fd;

	if (ft_read_map(filename, map) == -1)
		return (-1);
	ft_find_textures(map);
	if ((fd = open("textures/sky.kp", O_RDONLY)) != -1)
	{
		ft_trait_texture(fd, &map->sky);
		close(fd);
	}
	else
		return (-1);
	if ((fd = open("textures/floor.kp", O_RDONLY)) != -1)
	{
		ft_trait_texture(fd, &map->floor);
		close(fd);
	}
	else
		return (-1);
	return (0);
}
