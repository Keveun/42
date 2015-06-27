/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:44:02 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/12 16:48:07 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_list(t_list **list)
{
	t_list	*next;
	t_list	*plist;

	plist = *list;
	*list = NULL;
	while (plist)
	{
		next = plist->next;
		ft_strdel(&plist->content);
		free(plist);
		plist = next;
	}
}
