/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 10:11:25 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/26 16:13:54 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static int			ft_get_options(int argc, char **argv, int *args)
{
	char	options[6];
	int		flags;
	size_t	i;

	ft_strcpy(options, FLAGS);
	flags = 0;
	while (*args < argc)
	{
		if (ft_strlen(*argv) == 2 && ft_strstr(*argv, "--") && ++(*args))
			return (flags);
		if (**argv != '-' || ft_strlen(*argv) < 2)
			return (flags);
		++(*args);
		while (*(++(*argv)) != '\0')
		{
			i = 0;
			while (options[i] != **argv && options[i] != '\0')
				i++;
			if (i > 4)
				return (ft_error_options(**argv));
			flags |= 1 << i;
		}
		++argv;
	}
	return (flags);
}

static int		ft_options(char argc, char **argv, int *args)
{
	static int		flags = 0;

	if (args)
		flags = ft_get_options(argc, argv, args);
	return (flags);
}

static void		ft_file(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			if ((fd = open(*++argv, O_RDONLY)) != -1)
			{
				ft_nm(fd, *argv, argc - 2);
				close(fd);
			}
			else
				ft_error_file(*argv);
		}
	}
	else if ((fd = open("a.out", O_RDONLY)) != -1)
	{
		ft_nm(fd, *argv, argc - 1);
		close(fd);
	}
	else
		ft_putstr_fd("Error: ft_nm: can't open file: a.out (No such file or directory)\n", 2);
}

int				main(int argc, char **argv)
{
	int		args;

	args = 0;
	if (ft_options(argc - 1, argv + 1, &args) != -1)
	{
		argc -= args;
		argv += args;
		ft_file(argc, argv);
	}
	return (0);
}
