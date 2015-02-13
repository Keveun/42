/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:11:59 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/13 19:29:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_errors2(char *s2, int type)
{
	if (type == 3)
	{
		if (s2)
		{
			write(2, ": ", 2);
			write(2, s2, ft_strlen(s2));
		}
		write(2, ": No such file or directory\n", 28);
	}
	else if (type == 4)
	{
		write(2, ": ", 2);
		write(2, s2, ft_strlen(s2));
		write(2, ": Not a directory\n", 18);
	}
	else if (type == 5)
	{
		write(2, " : unknown option -- ", 21);
		write(2, s2 + 1, ft_strlen(s2) - 1);
		write(2, "\n", 1);
	}
}

void			ft_printerror(char *s1, char *s2, int type)
{
	write(2, "-", 1);
	write(2, NAME, ft_strlen(NAME));
	if (s1)
	{
		write(2, ": ", 2);
		write(2, s1, ft_strlen(s1));
	}
	if (type == 1)
		write(2, " : command not found\n", 21);
	else if (type == 2)
		write(2, " : Permission denied\n", 21);
	else if (type >= 3)
		ft_errors2(s2, type);
}

int				ft_error_args(char **cmd, int min, int max)
{
	if (ft_count_tabelem(cmd) > max)
	{
		write(2, "-", 1);
		write(2, NAME, ft_strlen(NAME));
		write(2, ": ", 2);
		write(2, *cmd, ft_strlen(*cmd));
		write(2, ": Too many arguments\n", 21);
		return (1);
	}
	else if (ft_count_tabelem(cmd) < min)
	{
		write(2, "-", 1);
		write(2, NAME, ft_strlen(NAME));
		write(2, ": ", 2);
		write(2, *cmd, ft_strlen(*cmd));
		write(2, ": Too few arguments\n", 20);
		return (1);
	}
	return (0);
}

int				ft_env_error(char **cmd, int type)
{
	write(2, "-", 1);
	write(2, NAME, ft_strlen(NAME));
	if (type == 1)
	{
		if (ft_count_tabelem(cmd) > 1)
		{
			write(2, ": ", 2);
			write(2, *cmd, ft_strlen(*cmd));
			write(2, ": Too many arguments\n", 21);
			return (1);
		}
	}
	else if (type == 2)
	{
		write(2, ": ", 2);
		write(2, "cd -", 4);
		write(2, ": OLDPWD not set\n", 17);
	}
	else if (type == 3)
	{
		write(2, ": ", 2);
		write(2, "cd", 2);
		write(2, ": HOME not set\n", 15);
	}
	return (0);
}
