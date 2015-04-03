/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/30 20:39:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_find_longest(t_args *args, int end)
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
	char	*res;
	int		i;
	int		j;
	t_args	*tmp;

	i = -1;
	j = 0;
	tmp = infos->args;
	while (++i < infos->nbr_args)
	{
		if (infos->cursor.x > infos->size.ws_col)
			break ;
		res = tgetstr("cm", NULL);
		tputs(tgoto(res, infos->cursor.x, infos->cursor.y), 1, ft_my_outc);
		write(1, infos->args[i].str, infos->args[i].len - \
			((infos->args[i].len + infos->cursor.x > infos->size.ws_col) ? \
			(infos->args[i].len + infos->cursor.x) - infos->size.ws_col : 0));
		++j;
		if (++infos->cursor.y > infos->size.ws_row)
		{
			infos->cursor.y = 0;
			infos->cursor.x += ft_find_longest(tmp, j) + 2;
			tmp += j;
			j = 0;
		}
	}
	return (0);
}