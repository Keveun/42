/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 10:11:25 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/22 19:00:20 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int				main(int argc, char **argv)
{
	int		fd;
	int		i;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			if ((fd = open(*++argv, O_RDONLY)) != -1)
			{
				ft_nm(fd, *argv, argc - 2);
				close(fd);
			}
			else
				ft_putstr_fd("Erreur: file not found or bad permission.\n", 2);
		}
	}
	else if ((fd = open("a.out", O_RDONLY)) != -1)
	{
		ft_nm(fd, *argv, argc - 1);
		close(fd);
	}
	else
		ft_putstr_fd("Erreur: a.out not found or bad permission.\n", 2);
	return (0);
}
