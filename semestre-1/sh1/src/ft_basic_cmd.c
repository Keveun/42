/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:11:11 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/12 18:52:10 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_cmd_bin(char **cmd, t_list **lenv)
{
	pid_t	father;
	char	*path;
	char	**paths;
	char	**my_env;
	char	envi;

	path = (lenv) ? ft_findpath(*lenv) : NULL;
	paths = ft_strsplit(path, ':');
	envi = (!ft_strcmp(*cmd, "env") && !ft_strcmp(cmd[1], "-i")) ? 2 : 0;
	if (*(cmd + envi) && (path = ft_getpath(paths, cmd + envi)))
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		my_env = (!envi) ? ft_list_to_tab(*lenv) : NULL;
		if (father == 0)
		{
			signal(SIGINT, SIG_DFL);
			execve(path, cmd + envi, my_env);
		}
		free(my_env);
	}
	if (paths)
		ft_freetab(paths);
}

void	ft_cmd_exit(char **cmd, t_list **lenv)
{
	(void)cmd;
	(void)lenv;
	exit(0);
}

void	ft_cmd_env(char **cmd, t_list **lenv)
{
	char	*var;
	char	*temp;

	if (!*lenv)
		return ;
	if (!cmd[1])
		ft_show_list(*lenv, 1);
	else if (*cmd[1] == '-')
	{
		if (!ft_strcmp(cmd[1], "-0"))
			ft_show_list(*lenv, 0);
		else if (!ft_strcmp(cmd[1], "-i"))
			ft_cmd_bin(cmd, lenv);
		else
			ft_printerror(cmd[0], cmd[1], 5);
	}
	else
	{
		temp = ft_str_tolower(ft_strdup(cmd[1]));
		if ((var = ft_find_var(*lenv, temp, 1)))
			ft_putendl(var + ft_strlen(cmd[1]) + 1);
		else
			ft_printerror(cmd[0], cmd[1], 3);
		free(temp);
	}
}

void	ft_cmd_setenv(char **cmd, t_list **lenv)
{
	t_list	*elem;

	if (ft_strchr(cmd[1], '='))
	{
		if (*lenv && (elem = ft_find_env(*lenv, cmd[1])))
		{
			free(elem->content);
			elem->content = ft_strdup(cmd[1]);
		}
		else
			*lenv = ft_add_list(*lenv, ft_strdup(cmd[1]));
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
