/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 19:07:13 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/18 22:56:46 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

char			*ft_realloc_buffer(char *buf, int *d_buf)
{
	*d_buf *= 2;
	free(buf);
	if ((buf = (char*)malloc(sizeof(char) * (*d_buf + 1))) == NULL)
		return (0);
	return (buf);
}

int				ft_read_stdin(char *filename)
{
	int		ret;
	int		fd;
	char	*buf;
	int		d_buf;

	d_buf = BUF_SIZE;
	if ((!(buf = (char*)malloc(sizeof(char) * (d_buf + 1)))) ||
		((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
					| S_IRGRP | S_IROTH)) == -1))
		return (0);
	while ((ret = read(0, buf, d_buf)) > 0)
	{
		buf[ret] = '\0';
		if ((write(fd, buf, ret) != ret) ||
			(d_buf * 2 < BUF_MAX && !(buf = ft_realloc_buffer(buf, &d_buf))))
			return (0);
	}
	free(buf);
	close(fd);
	return (1);
}

static int		ft_calcul_header(t_data *data, char *buf)
{
	int		start_len;
	int		strlen_n;

	start_len = 0;
	if (!data->len && !(start_len = ft_check_first_line(buf, data)))
		return (0);
	strlen_n = ft_strlen_n(buf, start_len);
	data->len += strlen_n;
	if (buf[start_len + strlen_n] == '\n')
	{
		if ((data->map = malloc(sizeof(int) * data->len)) == NULL)
			return (0);
		return (-1);
	}
	return (1);
}

int				ft_header(char *filename, t_data *data)
{
	char	*buf;
	int		ret;
	int		fd;
	int		result;
	int		d_buf;

	d_buf = BUF_SIZE;
	if (((buf = (char*)malloc(sizeof(char) * (d_buf + 1))) == NULL) ||
		((fd = open(filename, O_RDONLY)) == -1))
		return (0);
	while ((ret = read(fd, buf, d_buf)))
	{
		buf[ret] = '\0';
		if (!(result = ft_calcul_header(data, buf)))
			return (0);
		if (result == -1)
			break ;
		if (d_buf * 2 < BUF_MAX && !(buf = ft_realloc_buffer(buf, &d_buf)))
			return (0);
	}
	free(buf);
	close(fd);
	return (data->len ? 1 : 0);
}