/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:02:57 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/22 13:53:01 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_delete(t_infos *infos)
{
	int		l;
	t_args	*tmp;

	l = infos->lastid;
	infos->args[l].selected = 0;
	--infos->nbr_args;
	if (infos->nbr_args > 0)
	{
		if (infos->lastid >= infos->nbr_args)
			--infos->lastid;
		tmp = infos->args;
		infos->args = ft_n_args(infos->nbr_args, infos, l);
		free(tmp);
		ft_display(infos);
	}
	else
		return (-1);
	return (0);
}
