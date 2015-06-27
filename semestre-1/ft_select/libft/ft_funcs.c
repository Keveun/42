/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 14:41:44 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/04 15:32:23 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init(t_info **info)
{
	t_info	*pinfo;

	if (!(*info = (t_info*)malloc(sizeof(t_info))))
		return ;
	pinfo = *info;
	pinfo->head = NULL;
	pinfo->tail = NULL;
	pinfo->len = 0;
}
