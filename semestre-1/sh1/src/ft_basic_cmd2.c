/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_cmd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 03:09:00 by Kevin             #+#    #+#             */
/*   Updated: 2015/02/01 03:09:02 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_cd_env(t_list **lenv, char *var, char *cmd)
{
	char	*dir;
	char	*pwd[2];

	dir = ft_find_var(*lenv, var, 0);
	dir = (dir) ? dir + ft_strlen(var) : NULL;
	if (dir && chdir(dir) != -1)
	{
		if (!ft_strcmp(var, "OLDPWD="))
			ft_putendl(dir);
		pwd[1] = ft_strjoin("PWD=", dir);
		ft_cmd_setenv(pwd, lenv);
		free(pwd[1]);
		return (1);
	}
	else
		ft_printerror(cmd, dir, 4);
	return (0);
}

static int		ft_cd_dir(t_list **lenv, char **cmd)
{
	char	*pwd[2];

	if (chdir(cmd[1]) != -1)
	{
		pwd[1] = ft_strjoin("PWD=", cmd[1]);
		ft_cmd_setenv(pwd, lenv);
		free(pwd[1]);
		return (1);
	}
	else
		ft_printerror(*cmd, cmd[1], 4);
	return (0);
}

static char		*ft_getpwd(t_list **lenv)
{
	char	*pwd[2];
	char	buf[2048];

	if ((*pwd = ft_find_var(*lenv, "PWD=", 0)))
		*pwd = ft_strdup(*pwd + 4);
	else
	{
		*pwd = ft_strdup(getcwd(buf, 2048));
		pwd[1] = ft_strjoin("PWD=", *pwd);
		ft_cmd_setenv(pwd, lenv);
		free(pwd[1]);
	}
	return (*pwd);
}

void			ft_cmd_cd(char **cmd, t_list **lenv)
{
	char	*pwd[2];
	int		success;

	*pwd = ft_getpwd(lenv);
	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
		success = ft_cd_env(lenv, "HOME=", *cmd);
	else
	{
		if (!ft_strcmp(cmd[1], "-"))
			success = ft_cd_env(lenv, "OLDPWD=", *cmd);
		else
		{
			if (!ft_strncmp(cmd[1], "~/", 2))
			{
				pwd[1] = ft_find_var(*lenv, "HOME=", 0) + 5;
				pwd[1] = ft_strjoin(pwd[1], cmd[1] + 1);
				free(cmd[1]);
				cmd[1] = pwd[1];
			}
			success = ft_cd_dir(lenv, cmd);
		}
	}
	pwd[1] = ft_strjoin("OLDPWD=", *pwd);
	free(*pwd);
	if (success)
		ft_cmd_setenv(pwd, lenv);
	free(pwd[1]);
}