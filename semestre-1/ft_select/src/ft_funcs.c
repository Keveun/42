/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/27 15:24:25 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_my_outc(int c)
{
	t_infos		*infos;

	infos = ft_singleton();
	write(infos->fd, &c, 1);
	return (0);
}

void		ft_select_all(t_infos *infos, int code)
{
	int		i;

	i = -1;
	while (++i < infos->nbr_args)
		infos->args[i].selected = code;
	ft_display(infos);
}

void		ft_selected(t_infos *infos)
{
	int		l;
	int		len;

	l = infos->lastid;
	infos->args[l].selected = !infos->args[l].selected;
	len = infos->args[l].len - \
		((infos->args[l].c.x + infos->args[l].len > infos->size.ws_col) ? \
		(infos->args[l].c.x + infos->args[l].len) - infos->size.ws_col : 0);
	tputs(tgoto(infos->cm, infos->args[l].c.x, infos->args[l].c.y)\
		, 1, ft_my_outc);
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

void		ft_rewrite(t_infos *infos, int l, int n)
{
	int		len;

	tputs(tgoto(infos->cm, infos->args[l].c.x, infos->args[l].c.y)\
		, 1, ft_my_outc);
	len = infos->args[l].len - \
		((infos->args[l].c.x + infos->args[l].len > infos->size.ws_col) ? \
		(infos->args[l].c.x + infos->args[l].len) - infos->size.ws_col : 0);
	if (infos->args[l].selected)
		tputs(infos->mr, 1, ft_my_outc);
	write(infos->fd, infos->args[l].str, len);
	tputs(infos->me, 1, ft_my_outc);
	tputs(tgoto(infos->cm, infos->args[n].c.x, infos->args[n].c.y)\
		, 1, ft_my_outc);
	tputs(infos->us, 0, ft_my_outc);
	len = infos->args[n].len - \
		((infos->args[n].c.x + infos->args[n].len > infos->size.ws_col) ? \
		(infos->args[n].c.x + infos->args[n].len) - infos->size.ws_col : 0);
	if (infos->args[n].selected)
		tputs(infos->mr, 1, ft_my_outc);
	write(infos->fd, infos->args[n].str, len);
	tputs(infos->me, 1, ft_my_outc);
}

void		ft_calc_val(t_infos *infos, int value, int lid)
{
	if (!infos->redisp && !infos->error)
		ft_rewrite(infos, lid, value);
	infos->cursor.x = infos->args[value].c.x;
	infos->cursor.y = infos->args[value].c.y;
	infos->args[value].cursor = 1;
	infos->args[lid].cursor = 0;
	infos->lastid = value;
	infos->redisp = 0;
}
