/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 17:27:46 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 17:53:02 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_rewrite(t_infos *infos, int l, int n)
{
	int		len;

	tputs(tgoto(infos->cm, infos->args[l].c.x, infos->args[l].c.y), 1, ft_my_outc);
	len = infos->args[l].len - \
		  ((infos->args[l].c.x + infos->args[l].len > infos->size.ws_col) ? \
		   (infos->args[l].c.x + infos->args[l].len) - infos->size.ws_col : 0);
	if (infos->args[l].selected)
		tputs(infos->mr, 1, ft_my_outc);
	write(infos->fd, infos->args[l].str, len);
	tputs(infos->me, 1, ft_my_outc);
	tputs(tgoto(infos->cm, infos->args[n].c.x, infos->args[n].c.y), 1, ft_my_outc);
	tputs(infos->us, 0, ft_my_outc);
	len = infos->args[n].len - \
		  ((infos->args[n].c.x + infos->args[n].len > infos->size.ws_col) ? \
		   (infos->args[n].c.x + infos->args[n].len) - infos->size.ws_col : 0);
	if (infos->args[n].selected)
		tputs(infos->mr, 1, ft_my_outc);
	write(infos->fd, infos->args[n].str, len);
	tputs(infos->me, 1, ft_my_outc);
}

static int		ft_jmp_right(t_infos *infos, int lid)
{
	int		value;

	value = lid + infos->size.ws_row;
	if (value >= infos->nbr_args)
		value -= infos->size.ws_row;
	else if (!infos->end && infos->args[value].col == infos->column)
	{
		if (infos->id_page)
			infos->page[infos->id_page] = infos->start;
		++infos->id_page;
		infos->start += infos->column * infos->size.ws_row;
		infos->lastid = value;
		ft_display(infos);
		infos->redisp = 1;
		infos->pos_col = 0;
	}
	else if (value < infos->nbr_args)
		++infos->pos_col;
	return (value);
}

static int		ft_jmp_left(t_infos *infos, int lid)
{
	int		value;
	int		tmp;

	value = lid - infos->size.ws_row;
	if (infos->pos_col)
		--infos->pos_col;
	else if (infos->start)
	{
		--infos->id_page;
		tmp = infos->start - infos->page[infos->id_page];
		infos->start = infos->page[infos->id_page];
		infos->lastid = value;
		ft_display(infos);
		infos->redisp = 1;
		infos->pos_col = (tmp / infos->size.ws_row) - 1;
	}
	if (value < 0)
		value += infos->size.ws_row;
	return (value);
}

static void		ft_selected(t_infos *infos)
{
	int		l;
	int		len;

	l = infos->lastid;
	infos->args[l].selected = !infos->args[l].selected;
	len = infos->args[l].len - \
		((infos->args[l].c.x + infos->args[l].len > infos->size.ws_col) ? \
		(infos->args[l].c.x + infos->args[l].len) - infos->size.ws_col : 0);
	tputs(tgoto(infos->cm, infos->args[l].c.x, infos->args[l].c.y), 1, ft_my_outc);
	tputs(infos->us, 1, ft_my_outc);
	if (infos->args[l].selected)
	{
		tputs(infos->mr, 1, ft_my_outc);
		++infos->nbr_selected;
	}
	else
		--infos->nbr_selected;
	write(infos->fd, infos->args[l].str, len);
	tputs(infos->me, 0, ft_my_outc);
}

static int		ft_top_bot(t_infos *infos, int key, int l)
{
	int		value;
	int		tmp;

	value = 0;
	if (key == K_TOP)
	{
		value = (l - 1 < 0) ? 0 : l - 1;
		if (!infos->args[l].c.y && !infos->args[l].col && infos->start)
		{
			--infos->id_page;
			tmp = infos->start - infos->page[infos->id_page];
			infos->start = infos->page[infos->id_page];
			infos->lastid = value;
			ft_display(infos);
			infos->redisp = 1;
			infos->pos_col = (tmp / infos->size.ws_row) - 1;
		}
	}
	else if (key == K_BOTTOM)
	{
		value = (l + 1 < infos->nbr_args) ? l + 1 : infos->nbr_args - 1;
		if (infos->args[l].c.y == infos->size.ws_row - 1 &&
				infos->args[l].col + 1 == infos->column &&
				!infos->end)
		{
			if (infos->id_page)
				infos->page[infos->id_page] = infos->start;
			++infos->id_page;
			infos->start += infos->column * infos->size.ws_row;
			infos->lastid = value;
			ft_display(infos);
			infos->redisp = 1;
			infos->pos_col = 0;
		}
	}
	return (value);
}

void			ft_moove(t_infos *infos, int key)
{
	int		lid;
	int		value;

	lid = infos->lastid;
	if (key == K_TOP || key == K_BOTTOM)
		value = ft_top_bot(infos, key, lid);
	else if (key == K_LEFT)
		value = ft_jmp_left(infos, lid);
	else if (key == K_RIGHT)
		value = ft_jmp_right(infos, lid);
	else if (key == K_SPACE)
	{
		ft_selected(infos);
		ft_moove(infos, K_BOTTOM);
	}
	else if (key == K_SELALL)
		ft_select_all(infos, 1);
	else if (key == K_DESELALL)
		ft_select_all(infos, 0);
	if (key == K_RIGHT || key == K_LEFT || key == K_TOP || key == K_BOTTOM)
	{
		value = (value < 0) ? infos->nbr_args - 1 : value % infos->nbr_args;
		if (!infos->redisp)
			ft_rewrite(infos, lid, value);
		infos->cursor.x = infos->args[value].c.x;
		infos->cursor.y = infos->args[value].c.y;
		infos->args[value].cursor = 1;
		infos->args[lid].cursor = 0;
		infos->lastid = value;
		infos->redisp = 0;
	}
}
