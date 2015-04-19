/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 18:25:52 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/19 18:46:11 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_out(t_infos *infos)
{
	int		i;

	i = -1;
	while (++i < infos->nbr_args)
	{
		if (infos->args[i].selected)
		{
			ft_putstr(infos->args[i].str);
			if (--infos->nbr_selected)
				ft_putchar(' ');
		}
	}
}
