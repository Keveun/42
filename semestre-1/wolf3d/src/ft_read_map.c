/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 19:07:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/15 19:20:49 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char		**ft_len_split(char *s, int height, int width)
{
	char	**tab;
	char	**begin;
	int		i;

	if ((tab = (char**)malloc(sizeof(char*) * height)) == NULL)
		return (NULL);
	begin = tab;
	i = -1;
	while (i++ < height)
	{
		*tab++ = s;
		s += width;
	}
	return (begin);
}

int				ft_read_map(char *filename, t_map *map)
{
	int		fd;
	char	buff[5];
	char	*data;

	if ((fd = open(filename, O_RDONLY)) != -1)
	{
		read(fd, buff, 5);
		map->height = (int)ft_atoi(buff);
		read(fd, buff, 5);
		map->width = (int)ft_atoi(buff);
		if ((data = malloc(map->height * map->width)) == NULL)
			return (0);
		read(fd, data, map->height * map->width);
		map->data = ft_len_split(data, map->height, map->width);
		close(fd);
	}
	else
		return (-1);
	return (0);
}
