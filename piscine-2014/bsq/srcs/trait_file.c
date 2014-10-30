/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 19:11:56 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/18 22:55:27 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

static int		ft_min(t_data *data, int y)
{
	int min;

	min = data->check[0];
	if (data->map[y - 1] < min)
		min = data->map[y - 1];
	if (data->check[1] < min)
		min = data->check[1];
	return (min + 1);
}

static int		ft_matrix(t_data *data, int x, int y)
{
	if (data->map[y] && y && x)
		data->map[y] = ft_min(data, y);
	if (data->bsq[2] < data->map[y])
	{
		data->bsq[0] = x;
		data->bsq[1] = y;
		data->bsq[2] = data->map[y];
	}
	return (1);
}

static char		*ft_make_map(char *buf, t_data *data, int *line)
{
	int		k;

	k = data->offset;
	while (*buf != '\n' && *buf)
	{
		if (++k > data->len - 1 ||
			((*buf ^ data->str[0]) &&
			(*buf ^ data->str[1])))
			return (0);
		data->check[0] = data->check[1];
		data->check[1] = data->map[k];
		data->map[k] = (*buf == data->str[0]) ? 1 : 0;
		ft_matrix(data, *line, k);
		++buf;
	}
	data->offset = (k < (data->len - 1)) ? k : -1;
	if ((k == data->len - 1) &&
		(++(*line) > data->total_lines))
		return (0);
	return (*buf ? ++buf : buf);
}

static int		ft_buffer(char *buf, t_data *data, int *line)
{
	if (*line == -1)
	{
		buf += data->hlen;
		*line = 0;
	}
	while (*buf)
		if (!(buf = ft_make_map(buf, data, line)))
			return (0);
	return (1);
}

int			ft_read_file(char *filename, t_data *data)
{
	char	*buf;
	int		line;
	int		ret;
	int		fd;
	int		d_buf;

	d_buf = BUF_SIZE;
	if ((!ft_header(filename, data)) ||
		((buf = (char*)malloc(sizeof(char) * (d_buf + 1))) == NULL) ||
		((fd = open(filename, O_RDONLY)) == -1))
		return (0);
	line = -1;
	while ((ret = read(fd, buf, d_buf)))
	{
		buf[ret] = '\0';
		if (!ft_buffer(buf, data, &line))
			return (0);
		if ((line % 301 && d_buf * 2 < BUF_MAX) &&
			(!(buf = ft_realloc_buffer(buf, &d_buf))))
			return (0);
	}
	free(buf);
	close(fd);
	return (line == data->total_lines ? 1 : 0);
}