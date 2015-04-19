/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/19 20:27:10 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_args			*ft_args(int argc, char **argv)
{
	t_args	*args;
	t_args	*begin;

	if ((args = malloc(sizeof(t_args) * (argc + 1))) == NULL)
		return (NULL);
	begin = args;
	while (argc--)
	{
		args->len = ft_strlen(*argv);
		args->visible = 1;
		args->selected = 0;
		args->cursor = (args == begin) ? 1 : 0;
		(args++)->str = *argv++;
	}
	return (begin);
}

t_args			*ft_n_args(int argc, t_infos *infos, int id)
{
	t_args	*args;
	int		i;
	int		j;

	if ((args = malloc(sizeof(t_args) * (argc + 1))) == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (++i <= argc)
	{
		if (i != id)
		{
			args[j].len = infos->args[i].len;
			args[j].selected = infos->args[i].selected;
			args[j].cursor = (j == infos->lastid) ? 1 : 0;
			args[j].str = infos->args[i].str;
			++j;
		}
	}
	return (args);
}
