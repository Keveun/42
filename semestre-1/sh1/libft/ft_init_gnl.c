/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 14:41:44 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/27 19:05:29 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_gnl(t_info **info)
{
	t_info	*pinfo;

	if (!(*info = (t_info*)malloc(sizeof(t_info))))
		return ;
	pinfo = *info;
	pinfo->head = NULL;
	pinfo->tail = NULL;
	pinfo->len = 0;
}

int		ft_reset_gnl(t_info **info)
{
	free(*info);
	*info = NULL;
	return (0);
}
