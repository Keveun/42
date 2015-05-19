/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 17:20:59 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/26 17:36:14 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_reset(t_infos *infos)
{
	t_args *tmp;



	tmp = infos->args;
	infos->args = ft_reset_args(infos);
	infos->nbr_args = infos->nbr_rargs;
	free(tmp);
	ft_display(infos);
}
