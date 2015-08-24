/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:23:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:23:19 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_tab_to_list(char **tab)
{
	t_list	*list;

	if (!tab)
		return (NULL);
	list = NULL;
	while (*tab)
	{
		list = ft_add_list(list, ft_strdup(*tab));
		++tab;
	}
	return (list);
}
