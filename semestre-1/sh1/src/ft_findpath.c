/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:12:16 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/12 18:21:11 by kperreau         ###   ########.fr       */
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
		if (!*tofind && *(s - 1) == '=')
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
			ft_printerror(pathname, NULL, 2);
		return (-1);
	}
	return (0);
}

char			*ft_getpath(char **paths, char **cmd)
{
	char	*pathname;
	int		ret;

	ret = 1;
	if (ft_ishere(**cmd, *cmd))
	{
		pathname = ft_strdup(*cmd);
		if ((ret = ft_checkpath(pathname)))
			return ((ret == 1) ? pathname : NULL);
		ret = 3;
		free(pathname);
	}
	else if (paths)
	{
		while (*paths)
		{
			pathname = ft_pathname(*paths++, *cmd);
			if ((ret = ft_checkpath(pathname)))
				return ((ret == 1) ? pathname : NULL);
			free(pathname);
		}
		ret = 1;
	}
	ft_printerror(*cmd, NULL, ret);
	return (NULL);
}

char			*ft_find_var(t_list *lenv, char *tofind, int type)
{
	char	*s;
	char	*begin;

	begin = tofind;
	while (lenv)
	{
		s = lenv->content;
		tofind = begin;
		while (*tofind && *s)
		{
			if (*tofind++ != *s++)
				break ;
		}
		if (!*tofind && ((!type && *(s - 1) == '=') || (type && *s == '=')))
			return (lenv->content);
		lenv = lenv->next;
	}
	return (NULL);
}
