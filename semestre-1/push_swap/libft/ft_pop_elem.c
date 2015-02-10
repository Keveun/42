/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 00:13:19 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/31 00:13:20 by Kevin            ###   ########.fr       */
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
