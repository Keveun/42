/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/04 20:54:34 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_my_outc(int c)
{
	t_infos		*infos;

	infos = ft_singleton();
	// ft_putchar(c);
	write(infos->fd, &c, 1);
	return (0);
}

// int			ft_find_start(t_infos *infos)
// {
	// int		val;
	// int		i;

	// val = 0;
	// i = infos->start;
	// while ()
	// return (val);
// }