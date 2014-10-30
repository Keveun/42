/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gservett <gservett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 00:45:08 by gservett          #+#    #+#             */
/*   Updated: 2014/09/15 15:08:01 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE	1

#include "../includes/colle2.h"

char	*ft_input(int *result, char *value)
{
	char	buf[BUF_SIZE];
	char	*c;
	int		i[2];
	t_list	*list;
	
	list = NULL;
	i[0] = 0;
	while ((i[1] = read(0, buf, BUF_SIZE)))
	{
		c = (char*)malloc(sizeof(char));
		*c = *buf;
		ft_list_push_back(&list, c);
		i[0]++;
	}
	value = malloc(sizeof(char) * i[0]);
	i[0] = 0;
	while (list)
	{
		value[i[0]] = *(char*)list->data;
		list = list->next;
		i[0]++;
	}
	size(value, result);
	return (value);
}

int		main(void)
{
	int 	result[3];
	char	*value;
	char	*gen_square;
	
	value = NULL;
	value = ft_input(result, value);
	gen_square = malloc(sizeof(char) * ft_strlen(value) + 1);
	loop_square(result[0], result[1], gen_square, value);
	ft_putstr("\n");
	return (0);
}
