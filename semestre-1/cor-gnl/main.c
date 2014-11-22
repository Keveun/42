/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:56:05 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/22 18:58:24 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc > 1)
	{
		if (argc > 2 || (fd = open(argv[1], O_RDONLY)) != -1)
		{
			if (argc > 2)
				fd = 0;
			if (argc > 3)
				fd = 42;
			while (get_next_line(fd, &line) == 1)
			{
				ft_putstr(line);
				ft_strdel(&line);
			}
		}
		close(fd);
	}
	return (0);
}
