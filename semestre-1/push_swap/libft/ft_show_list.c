/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 03:08:17 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/31 03:08:19 by Kevin            ###   ########.fr       */
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