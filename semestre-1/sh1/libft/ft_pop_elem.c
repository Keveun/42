/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:22:22 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:22:27 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pop_elem(t_list *elem, t_list *prev)
{
	if (prev)
	{
		if (prev->next != elem)
		{
			while (prev)
			{
				if (prev->next == elem)
					break ;
				prev = prev->next;
			}
			prev->next = elem->next;
		}
	}
	free(elem);
}
