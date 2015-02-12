/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 20:15:39 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/21 20:15:52 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file		*ft_init_file(t_file *file, int fd, int type)
{
	t_file	*new;

	if (type)
	{
		new = (file->prev) ? file->prev : file->next;
		free(file);
		return (new);
	}
	if ((new = malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if (file)
	{
		while (file->next)
			file = file->next;
		file->next = new;
		new->prev = file;
	}
	else
		new->prev = NULL;
	new->next = NULL;
	new->fd = fd;
	new->buff = NULL;
	new->begin = NULL;
	return (new);
}

static t_file		*ft_find_del_fd(int fd, t_file *file, char **line, int type)
{
	if (type == 1)
	{
		*line = ft_strdup(file->buff);
		ft_strdel(&file->begin);
		file->buff = NULL;
		return (NULL);
	}
	else if (type == 2)
	{
		if (file->prev)
			(file->prev)->next = file->next;
		if (file->next)
			(file->next)->prev = file->prev;
		file = ft_init_file(file, 0, 1);
		return (file);
	}
	while (file->prev)
		file = file->prev;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	return (NULL);
}

static int			ft_line(t_file *file, char *buff, char **line, int ret)
{
	char	*find;
	char	*temp;

	buff[ret] = '\0';
	temp = file->begin;
	if ((find = ft_strchr(buff, '\n')))
	{
		*find = '\0';
		*line = ft_strjoin(file->buff, buff);
		file->buff = ft_strdup(find + 1);
	}
	else
		file->buff = ft_strjoin(file->buff, buff);
	file->begin = file->buff;
	free(temp);
	return ((find) ? 1 : 0);
}

static int			ft_stack(t_file *file, char **line)
{
	char	*find;

	if (!(find = ft_strchr(file->buff, '\n')))
		return (0);
	*find = '\0';
	*line = ft_strdup(file->buff);
	file->buff = find + 1;
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*temp;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	temp = file;
	if (!file || !(file = ft_find_del_fd(fd, file, NULL, 0)))
		file = ft_init_file(temp, fd, 0);
	if (file->buff && ft_stack(file, line))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ft_line(file, buff, line, ret))
			return (1);
	}
	if (file->buff && !ret)
	{
		ft_find_del_fd(0, file, line, 1);
		return (0);
	}
	file = ft_find_del_fd(0, file, line, 2);
	return (ret);
}
