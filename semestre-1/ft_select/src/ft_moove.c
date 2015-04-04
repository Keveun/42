/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 17:27:46 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/04 21:30:48 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_rewrite(t_infos *infos, int l, int n)
{
	char	*res;
	int		len;

	l = infos->lastid;
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, infos->args[l].c.x, infos->args[l].c.y), 1, ft_my_outc);
	len = infos->args[l].len - \
		((infos->args[l].c.x + infos->args[l].len > infos->size.ws_col) ? \
		(infos->args[l].c.x + infos->args[l].len) - infos->size.ws_col : 0);
	write(1, infos->args[l].str, len);
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, infos->args[n].c.x, infos->args[n].c.y), 1, ft_my_outc);
	tputs(infos->us, 0, ft_my_outc);
	len = infos->args[n].len - \
		((infos->args[n].c.x + infos->args[n].len > infos->size.ws_col) ? \
		(infos->args[n].c.x + infos->args[n].len) - infos->size.ws_col : 0);
	write(1, infos->args[n].str, len);
	tputs(infos->ue, 0, ft_my_outc);
}

static int		ft_jmp_right(t_infos *infos, int lid)
{
	int		value;

	value = lid + infos->size.ws_row;
	if (value >= infos->nbr_args)
		value = (lid % infos->size.ws_row);
	return (value);
}

static int		ft_jmp_left(t_infos *infos, int lid)
{
	int		value;

	value = lid - infos->size.ws_row;
	if (value < 0)
	{
		value = (int)(infos->nbr_args / infos->size.ws_row) * \
			infos->size.ws_row + lid; 
		if (value >= infos->nbr_args)
			value -= infos->size.ws_row;
	}
	return (value);
}

void			ft_moove(t_infos *infos, int key)
{
	int		lid;
	int		value;

	lid = infos->lastid;
	if (key == K_TOP)
		value = lid - 1;
	else if (key == K_BOTTOM)
		value = lid + 1;
	else if (key == K_LEFT)
		value = ft_jmp_left(infos, lid);
	else if (key == K_RIGHT)
		value = ft_jmp_right(infos, lid);
	if (key == K_RIGHT || key == K_LEFT || key == K_TOP || key == K_BOTTOM)
	{
		value = (value < 0) ? infos->nbr_args - 1 : value % infos->nbr_args;
		ft_rewrite(infos, lid, value);
		infos->cursor.x = infos->args[value].c.x;
		infos->cursor.y = infos->args[value].c.y;
		infos->args[value].cursor = 1;
		infos->args[lid].cursor = 0;
		infos->lastid = value;
	}
}
