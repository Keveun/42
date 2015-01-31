/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 00:38:11 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/31 00:38:12 by Kevin            ###   ########.fr       */
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
		list = ft_add_list(list, *tab);
		++tab;
	}
	return (list);
}