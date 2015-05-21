/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 18:01:04 by kperreau         ###   ########.fr       */
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

void		ft_init_disp(t_infos *infos)
{
	tputs(infos->cl, 1, ft_my_outc);
	infos->cursor.x = 0;
	infos->cursor.y = 0;
	infos->column = 0;
	infos->end = 0;
	infos->redisp = 0;
	infos->nbr_print = 0;
	infos->prev_nbr_args = 0;
	tputs(infos->me, 1, ft_my_outc);
}

int			ft_display(t_infos *infos)
{
	int		i;
	int		j;
	int		notok;
	t_args	*tmp;

	ft_init_disp(infos);
	i = infos->start - 1;
	notok = 0;
	j = 0;
	tmp = infos->args + infos->start;
	while (++i < infos->nbr_args)
	{
		tputs(tgoto(infos->cm, infos->cursor.x, infos->cursor.y), 1, ft_my_outc);
		if (infos->args[i].selected)
			tputs(infos->mr, 1, ft_my_outc);
		if (i == infos->lastid)
			tputs(infos->us, 0, ft_my_outc);
		infos->args[i].c.x = infos->cursor.x;
		infos->args[i].c.y = infos->cursor.y;
		infos->args[i].col = infos->column;
		if (infos->args[i].len + infos->cursor.x > infos->size.ws_col)
		{
			notok = 1;
			if (!infos->cursor.x)
			{
				ft_resize_error(infos);
				break ;
			}
		}
		else
			++infos->prev_nbr_args;
		++infos->nbr_print;
		write(infos->fd, infos->args[i].str, infos->args[i].len - \
			((infos->args[i].len + infos->cursor.x > infos->size.ws_col) ? \
			(infos->args[i].len + infos->cursor.x) - infos->size.ws_col : 0));
		if (infos->args[i].cursor)
			tputs(infos->ue, 0, ft_my_outc);
		++j;
		if (++infos->cursor.y >= infos->size.ws_row)
		{
			infos->cursor.y = 0;
			infos->cursor.x += ft_find_longest(tmp, j) + 2;
			if (infos->cursor.x > infos->size.ws_col)
				break ;
			++infos->column;
			tmp += j;
			j = 0;
		}
		tputs(infos->me, 1, ft_my_outc);
	}
	if (!notok && i == infos->nbr_args)
		infos->end = 1;
	return (0);
}
