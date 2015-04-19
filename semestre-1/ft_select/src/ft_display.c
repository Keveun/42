/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/19 20:30:23 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

int			ft_display(t_infos *infos)
{
	int		i;
	int		j;
	t_args	*tmp;

	tputs(infos->cl, 1, ft_my_outc);
	infos->cursor.x = 0;
	infos->cursor.y = 0;
	i = -1;
	j = 0;
	tmp = infos->args;
	while (++i < infos->nbr_args)
	{
		if (infos->cursor.x > infos->size.ws_col)
			break ;
		tputs(tgoto(infos->cm, infos->cursor.x, infos->cursor.y), 1, ft_my_outc);
		//if (infos->args[i].cursor)
		if (infos->args[i].selected)
			tputs(infos->mr, 1, ft_my_outc);
		if (i == infos->lastid)
			tputs(infos->us, 0, ft_my_outc);
		infos->args[i].c.x = infos->cursor.x;
		infos->args[i].c.y = infos->cursor.y;
		write(1, infos->args[i].str, infos->args[i].len - \
			((infos->args[i].len + infos->cursor.x > infos->size.ws_col) ? \
			(infos->args[i].len + infos->cursor.x) - infos->size.ws_col : 0));
		if (infos->args[i].cursor)
			tputs(infos->ue, 0, ft_my_outc);
		++j;
		if (++infos->cursor.y >= infos->size.ws_row)
		{
			infos->cursor.y = 0;
			infos->cursor.x += ft_find_longest(tmp, j) + 2;
			tmp += j;
			j = 0;
		}
		tputs(infos->me, 1, ft_my_outc);
	}
	return (0);
}
