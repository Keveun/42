/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:45:09 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/12 19:47:02 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_add_list(t_list *list, char *str)
{
	t_list	*new;
	t_list	*begin;

	begin = list;
	if ((new = ft_create_list(str)) == NULL)
		return (NULL);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		begin = new;
	return (begin);
}
