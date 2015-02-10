/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 00:45:12 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/31 00:45:13 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_list_to_tab(t_list *list)
{
	char	**tab;
	char	**begin;

	if (!list)
		return (NULL);
	tab = NULL;
	if ((tab = malloc(sizeof(char*) * (ft_count_elem(list) + 1))) == NULL)
		return (NULL);
	begin = tab;
	while (list)
	{
		*tab++ = list->content;
		list = list->next;
	}
	*tab = '\0';
	return (begin);
}