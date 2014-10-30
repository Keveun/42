/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 14:48:47 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/10 19:30:07 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->data);
		list = list->next;
		ft_putstr("\n");
	}
}

int		main(int argc, char **argv)
{
	t_list *list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (argc > 1)
	{
		list = ft_create_elem(argv[1]);
		ft_list_push_back(&list, argv[2]);
		list = ft_list_last(list);
	}
	print_list(list);
	return (0);
}
