/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 00:20:56 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/31 00:20:57 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_list		*ft_find_env(t_list *lenv, char *s)
{
	int		len;

	len = ft_strchr(s, '=') - s;
	while (lenv)
	{
		if (!ft_strncmp(lenv->content, s, len))
			return (lenv);
		lenv = lenv->next;
	}
	return (NULL);
}

t_list		*ft_find_envpop(t_list *lenv, char *s)
{
	int		len;

	len = ft_strlen(s);
	while (lenv)
	{
		if (!ft_strncmp(lenv->content, s, len) && *(lenv->content + len) == '=')
			return (lenv);
		lenv = lenv->next;
	}
	return (NULL);
}
