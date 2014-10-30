/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 19:42:00 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/10 22:10:19 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 0;
	while (i < ac)
	{
		if (i)
			list->next = ft_create_elem(av[i]);
		else
			list = ft_create_elem(av[0]);
		i++;
	}
}
