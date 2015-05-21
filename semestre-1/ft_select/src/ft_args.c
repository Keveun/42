/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 20:10:39 by kperreau         ###   ########.fr       */
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

t_args			*ft_reset_args(t_infos *infos)
{
	t_args	*args;
	int		i;

	if ((args = malloc(sizeof(t_args) * (infos->nbr_rargs + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i <= infos->nbr_rargs)
	{
		args[i].len = infos->reset[i].len;
		args[i].selected = infos->reset[i].selected;
		args[i].cursor = (i == infos->lastid) ? 1 : 0;
		args[i].str = infos->reset[i].str;
	}
	return (args);
}

int			ft_find_longest(t_args *args, int end)
{
	int		n;
	int		i;

	i = 0;
	n = args[i++].len;
	--end;
	while (end--)
	{
		if (args[i].len > n)
			n = args[i].len;
		++i;
	}
	return (n);
}
