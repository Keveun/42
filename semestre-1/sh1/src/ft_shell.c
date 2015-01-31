/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:44:31 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/19 17:26:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_exec(char **cmd, t_list *lenv)
{
	pid_t	father;
	char	*path;
	char	**paths;
	char	**my_env;

	path = ft_findpath(lenv);
	paths = ft_strsplit(path, ':');
	if ((path = ft_getpath(paths, cmd)))
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		my_env = ft_list_to_tab(lenv);
		if (father == 0)
			execve(path, cmd, my_env);
		free(my_env);
		my_env = NULL;
	}
}

static int	ft_parse_stdin(char *line, t_list **lenv)
{
	char	**cmd;
	t_list	*elem;

	cmd = ft_splitword(line);
	if (!cmd || !*cmd)
		return (0);
	if (!ft_strcmp("exit", *cmd))
		exit(0);
	else if (!ft_strcmp("env", *cmd))
		ft_show_list(*lenv, 1);
	else if (!ft_strcmp("unsetenv", *cmd))
	{
		if ((elem = ft_find_envpop(*lenv, cmd[1])))
		{
			if (elem == *lenv)
				*lenv = (*lenv)->next;
			ft_pop_elem(elem, *lenv);
		}
	}
	else if (!ft_strcmp("setenv", *cmd))
	{
		if (ft_strchr(cmd[1], '='))
		{
			if ((elem = ft_find_env(*lenv, cmd[1])))
				elem->content = ft_strdup(cmd[1]);
			else
				ft_add_list(*lenv, cmd[1]);
		}
	}
	else
		ft_exec(cmd, *lenv);
	return (0);
}

int				ft_shell(char **env)
{
	char	*line;
	t_list	*lenv;

	lenv = ft_tab_to_list(env);
	while (1)
	{
		write(1, "$> ", 3);
		if (get_next_line(0, &line) != 1)
			return (0);
		ft_parse_stdin(line, &lenv);
		free(line);
	}
	return (0);
}
