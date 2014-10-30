/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 22:21:18 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/10 22:51:52 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (begin_list)
	{
		i = 0;
		while (i < nbr)
		{
			begin_list = begin_list->next;
			i++;
		}
	}
	else
		begin_list = NULL;
	return (begin_list);
}
