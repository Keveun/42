/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:22:02 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:22:06 by kperreau         ###   ########.fr       */
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
