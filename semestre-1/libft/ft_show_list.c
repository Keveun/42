/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:22:56 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:23:01 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_show_list(t_list *list, int newline)
{
	while (list)
	{
		if (list->content)
			ft_putstr(list->content);
		if (newline)
			write(1, "\n", 1);
		list = list->next;
	}
}
