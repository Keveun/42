/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 04:20:19 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/28 04:20:31 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#define STRTOFIND "PATH="

char			*ft_findpath(t_list *lenv)
{
	char	*tofind;
	char	*s;

	while (lenv)
	{
		tofind = STRTOFIND;
		s = lenv->content;
		while (*tofind && *s)
		{
			if (*tofind++ != *s++)
				break ;
		}
		if (!*tofind)
			return (s);
		lenv = lenv->next;
	}
	return (NULL);
}

static char		*ft_pathname(char *s1, char *s2)
{
	char	*pname;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((pname = (char*)malloc(sizeof(char) * (len1 + len2 + 2))) == NULL)
		return (NULL);
	ft_strcpy(pname, s1);
	pname += len1;
	*pname++ = '/';
	ft_strcpy(pname, s2);
	pname += len2;
	*pname = '\0';
	return (pname - len1 - len2 - 1);
}

static int		ft_checkpath(char *pathname)
{
	if (access(pathname, F_OK) != -1)
	{
		if (access(pathname, X_OK) != -1)
			return (1);
		else
			ft_printerror(pathname, 2);
		return (-1);
	}
	return (0);
}

char			*ft_getpath(char **paths, char **cmd)
{
	char	*pathname;
	int		ret;

	if (**cmd == '/' || !ft_strncmp("./", *cmd, 2))
	{
		pathname = ft_strdup(*cmd);
		if ((ret = ft_checkpath(pathname)))
			return ((ret == 1) ? pathname : NULL);
		free(pathname);
	}
	else
	{
		while (*paths)
		{
			pathname = ft_pathname(*paths, *cmd);
			if ((ret = ft_checkpath(pathname)))
				return ((ret == 1) ? pathname : NULL);
			free(pathname);
			++paths;
		}
	}
	ft_printerror(*cmd, 1);
	return (NULL);
}