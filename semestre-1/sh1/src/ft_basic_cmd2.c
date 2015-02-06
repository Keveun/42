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

	dir = ft_find_var(*lenv, var);
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
		ft_printerror(cmd, 3);
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
		ft_printerror(*cmd, 3);
	return (0);
}

void			ft_cmd_cd(char **cmd, t_list **lenv)
{
	char	*pwd[2];
	char	buf[2048];
	int		success;

	if ((*pwd = ft_find_var(*lenv, "PWD=")))
		*pwd = ft_strdup(*pwd + 4);
	else
		*pwd = ft_strdup(getcwd(buf, 2048));
	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
		success = ft_cd_env(lenv, "HOME=", *cmd);
	else
	{
		if (!ft_strcmp(cmd[1], "-"))
			success = ft_cd_env(lenv, "OLDPWD=", *cmd);
		else
			success = ft_cd_dir(lenv, cmd);
	}
	pwd[1] = ft_strjoin("OLDPWD=", *pwd);
	free(*pwd);
	if (success)
		ft_cmd_setenv(pwd, lenv);
	free(pwd[1]);
}