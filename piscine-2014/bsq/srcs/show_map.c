/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 19:50:25 by kperreau          #+#    #+#             */
/*   Updated: 2014/10/09 03:17:43 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

static char		*ft_realloc_buf(char *buf, int *d_buf, int len)
{
	*d_buf = len + 1;
	free(buf);
	if ((buf = (char*)malloc(sizeof(char) * (*d_buf + 1))) == NULL)
		return (0);
	return (buf);
}

static void		ft_write_map(t_data *data, char *buf, int l)
{
	int i;

	i = -1;
	if (!(l > data->bsq[0] - data->bsq[2] + 1 && l <= data->bsq[0] + 1))
		write(1, buf, data->len + 1);
	else
		while (buf[++i])
		{
			if ((l > data->bsq[0] - data->bsq[2] + 1 && l < data->bsq[0] + 2) &&
				(i > data->bsq[1] - data->bsq[2] && i <= data->bsq[1]))
				write(1, &data->str[2], 1);
			else
			{
				if (i < data->bsq[1])
				{
					write(1, buf, data->bsq[1] - data->bsq[2] + 1);
					i = data->bsq[1] - data->bsq[2];
				}
				else
				{
					write(1, buf + i, (data->len - i + 1));
					return ;
				}
			}
		}
}

static int		ft_check_read(char *filename, t_data *data, int argc, int *line)
{
	*line = 0;
	if (!argc)
	{
		if (ft_read_stdin(filename) && ft_read_file(filename, data))
			return (1);
	}
	else
	{
		if (ft_read_file(filename, data))
			return (1);
	}
	return (0);
}

void			ft_show_map(char *filename, t_data *data, int argc)
{
	int		ret;
	int		fd;
	int		d_buf;
	char	*buf;
	int		line;

	if (ft_check_read(filename, data, argc, &line))
	{
		d_buf = data->hlen + 1;
		if (((buf = (char*)malloc(sizeof(char) * (d_buf + 1))) == NULL) ||
			((fd = open(filename, O_RDONLY)) == -1))
			return ;
		while ((ret = read(fd, buf, d_buf)))
		{
			buf[ret] = '\0';
			if (line)
				ft_write_map(data, buf, line);
			if (!line++ && !(buf = ft_realloc_buf(buf, &d_buf, data->len)))
				return ;
		}
		free(buf);
		close(fd);
	}
	else
		write(2, "map error\n", 10);
}