/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:02:57 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 17:32:35 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_delete(t_infos *infos)
{
	int		l;
	t_args	*tmp;
	int		tmp2;

	l = infos->lastid;
	infos->args[l].selected = 0;
	--infos->nbr_args;
	if (infos->nbr_args > 0)
	{
		if (l >= infos->nbr_args)
			--infos->lastid;
		tmp = infos->args;
		infos->args = ft_n_args(infos->nbr_args, infos, l);
		free(tmp);
		if (infos->end && infos->start && l == infos->start)
		{
			--infos->id_page;
			tmp2 = infos->start - infos->page[infos->id_page];
			infos->start = infos->page[infos->id_page];
			ft_display(infos);
			infos->pos_col = (tmp2 / infos->size.ws_row) - 1;
		}
		ft_display(infos);
		return (0);
	}
	return (-1);
}
