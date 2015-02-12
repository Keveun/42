/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:20:57 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:21:02 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_elem(t_list *list)
{
	int		n;

	if (!list)
		return (0);
	n = 0;
	while (list)
	{
		++n;
		list = list->next;
	}
	return (n);
}
