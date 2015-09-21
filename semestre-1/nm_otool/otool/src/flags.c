/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-pach <mde-pach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:09:08 by mde-pach          #+#    #+#             */
/*   Updated: 2015/09/04 12:31:03 by mde-pach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int				check_flag(char **av)
{
	int		i;
	int		j;
	int		flags;

	i = 1;
	j = 1;
	flags = 0;
	while (av[i] && av[i][0] == '-' && av[i][j])
	{
		if (!ft_strcmp(av[i], "--") && i++)
			break ;
		if (ft_strchr(FLAGS, av[i][j]) == NULL)
		{
			ft_printf("%s: invalid argument %c\nUsage: %s [-%s] [file ...]\n",
					av[0], av[i][j], av[0], FLAGS);
			return (-1);
		}
		else
			flags |= 1 << (ft_strchr(FLAGS, av[i][j]) - FLAGS);
		j++;
		if (!av[i][j] && i++)
			j = 1;
	}
	get_flags(flags);
	return (i);
}

unsigned int			get_flags(unsigned int flags)
{
	static unsigned int f = 0;

	if (flags != 0)
		f = flags;
	return (f);
}

int						ft_flags(char **av)
{
	int		ret;

	if (!av[1])
	{
		ft_printf("%s: no input file\nUsage: %s [-%s] [file ...]\n",
				av[0], av[0], FLAGS);
		return (-1);
	}
	if (av[1][0] != '-')
		return (1);
	if ((ret = check_flag(av)) == -1)
		return (-1);
	if (!av[ret])
	{
		ft_printf("%s: no input file\nUsage: %s [-%s] [file ...]\n",
				av[0], av[0], FLAGS);
		return (-1);
	}
	return (ret);
}
