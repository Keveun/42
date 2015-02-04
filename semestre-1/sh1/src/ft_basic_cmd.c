/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 03:07:18 by Kevin             #+#    #+#             */
/*   Updated: 2015/02/01 03:07:20 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_cmd_bin(char **cmd, t_list **lenv)
{
	pid_t	father;
	char	*path;
	char	**paths;
	char	**my_env;

	path = ft_findpath(*lenv);
	paths = ft_strsplit(path, ':');
	if ((path = ft_getpath(paths, cmd)))
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		my_env = ft_list_to_tab(*lenv);
		if (father == 0)
		{
			signal(SIGINT, SIG_DFL);
			execve(path, cmd, my_env);
		}
		free(my_env);
		my_env = NULL;
	}
}

void	ft_cmd_exit(char **cmd, t_list **lenv)
{
	exit(0);
}

void	ft_cmd_env(char **cmd, t_list **lenv)
{
	if (*lenv)
		ft_show_list(*lenv, 1);
}

void	ft_cmd_setenv(char **cmd, t_list **lenv)
{
	t_list	*elem;

	if (ft_strchr(cmd[1], '='))
	{
		if (*lenv && (elem = ft_find_env(*lenv, cmd[1])))
			elem->content = ft_strdup(cmd[1]);
		else
			*lenv = ft_add_list(*lenv, cmd[1]);
	}
}
void	ft_cmd_unsetenv(char **cmd, t_list **lenv)
{
	t_list	*elem;

	if (*lenv && (elem = ft_find_envpop(*lenv, cmd[1])))
	{
		if (elem == *lenv)
			*lenv = (*lenv)->next;
		ft_pop_elem(elem, *lenv);
	}
}
