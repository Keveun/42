/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:00:15 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/08 15:46:23 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*s;

	list = NULL;
	list = (t_list*)malloc(sizeof(t_list));
	if (list)
	{
		if (content != NULL)
		{
			s = ft_memalloc(content_size);
			s = ft_memcpy(s, content, content_size);
		}
		list->content = (content != NULL) ? s : NULL;
		list->content_size = (content) ? content_size : 0;
		list->next = NULL;
	}
	return (list);
}
