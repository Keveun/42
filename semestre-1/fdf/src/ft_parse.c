/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:26:22 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/30 22:35:38 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_isdigit2(int c)
{
	if (!(c >= '0' && c <= '9') && c != '-')
		return (0);
	return (1);
}

static int		ft_count(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0' && !ft_isdigit2(*str))
		++str;
	while (*str != '\0')
	{
		if (ft_isdigit2(*str))
		{
			++i;
			while (*str != '\0' && ft_isdigit2(*str))
				++str;
		}
		++str;
	}
	return (i);
}

static void		ft_get_line(t_point *map, char *str, int y, int len)
{
	int			i;
	int			j;
	char		c[15];

	j = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && !ft_isdigit2(*str))
			++str;
		if (ft_isdigit2(*str) && (!j || (j && !ft_isdigit2(*(str - 1)))))
		{
			i = 0;
			while (*str && ft_isdigit2(*str))
				c[i++] = *str++;
			c[i] = '\0';
			(map[j]).z = ft_atoi(c);
			(map[j]).x = j;
			(map[j]).y = y;
			(map[j]).len = len;
			++i;
			++j;
		}
		else
			++str;
	}
}

static t_point	**ft_parse(t_list *list, int size)
{
	t_point		**map;
	int			i;
	int			len;
	t_list		*begin;

	map = NULL;
	begin = list;
	if ((map = (t_point**)malloc(sizeof(t_point*) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (list)
	{
		len = ft_count(list->content);
		if ((map[i] = (t_point*)malloc(sizeof(t_point) * len + 1)) == NULL)
			return (NULL);
		ft_get_line(map[i], list->content, i, len);
		++i;
		list = list->next;
	}
	map[i] = '\0';
	ft_del_list(&begin);
	return (map);
}

t_point			**ft_read_file(char *filename)
{
	int			fd;
	char		*line;
	int			i;
	t_list		*list;
	t_point		**map;

	line = NULL;
	i = -1;
	list = NULL;
	map = NULL;
	if ((fd = open(filename, O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &line) == 1 && ++i < 2000)
			list = ft_add_list(list, line);
		close(fd);
		if (list)
			map = ft_parse(list, i);
	}
	else
		ft_error("No such file.\n");
	return (map);
}
