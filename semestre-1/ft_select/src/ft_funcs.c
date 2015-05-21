/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 17:58:30 by kperreau         ###   ########.fr       */
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

void			ft_select_all(t_infos *infos, int code)
{
	int		i;

	i = -1;
	while (++i < infos->nbr_args)
		infos->args[i].selected = code;
	ft_display(infos);
}

