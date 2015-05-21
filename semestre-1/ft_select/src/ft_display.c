/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 20:11:03 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_init_disp(t_infos *infos, int *notok)
{
	tputs(infos->cl, 1, ft_my_outc);
	infos->cursor.x = 0;
	infos->cursor.y = 0;
	infos->column = 0;
	infos->end = 0;
	infos->redisp = 0;
	infos->nbr_print = 0;
	infos->prev_nbr_args = 0;
	if (notok)
		*notok = 0;
	tputs(infos->me, 1, ft_my_outc);
}

static int	ft_is_ok(t_infos *infos, int *notok)
{
	*notok = 1;
	if (!infos->cursor.x)
	{
		ft_resize_error(infos);
		return (1);
	}
	return (0);
}

static void	ft_norme_disp(t_infos *infos, int i)
{
	tputs(tgoto(infos->cm, infos->cursor.x, infos->cursor.y)\
		, 1, ft_my_outc);
	if (infos->args[i].selected)
		tputs(infos->mr, 1, ft_my_outc);
	if (i == infos->lastid)
		tputs(infos->us, 0, ft_my_outc);
	infos->args[i].c.x = infos->cursor.x;
	infos->args[i].c.y = infos->cursor.y;
	infos->args[i].col = infos->column;
}

int			ft_display(t_infos *infos)
{
	int		i;
	int		j;
	int		notok;
	t_args	*tmp;

	ft_init_disp(infos, &notok);
	i = infos->start - 1;
	j = 0;
	tmp = infos->args + infos->start;
	while (++i < infos->nbr_args)
	{
		ft_norme_disp(infos, i);
		if (infos->args[i].len + infos->cursor.x > infos->size.ws_col
			&& ft_is_ok(infos, &notok))
			break ;
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
