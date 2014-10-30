/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 01:27:50 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/09 19:15:56 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int	*tab_copy;
	int i;

	i = 0;
	if ((tab_copy = malloc(sizeof(int) * length)) == NULL)
		return (0);
	while (i < length)
	{
		tab_copy[i] = f(tab[i]);
		i++;
	}
	return (tab_copy);
}
