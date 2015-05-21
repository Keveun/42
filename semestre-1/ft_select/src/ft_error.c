/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 15:40:44 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 20:02:52 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		ft_resize_error(t_infos *infos)
{
	int		x;
	int		y;

	y = -1;
	ft_init_disp(infos, NULL);
	tputs(infos->me, 0, ft_my_outc);
	ft_putstr_fd(ANSI_COLOR_RED, infos->fd);
	while (++y <= infos->size.ws_row)
	{
		x = -1;
		while (++x < infos->size.ws_col)
			ft_putstr_fd("X", infos->fd);
		tputs(tgoto(infos->cm, 0, y), 1, ft_my_outc);
	}
	ft_putstr_fd(COLOR_RESET, infos->fd);
}
