/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:42:30 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/12 16:09:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_create_list(char *str)
{
	t_list			*list;

	list = NULL;
	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = str;
	list->next = NULL;
	return (list);
}
