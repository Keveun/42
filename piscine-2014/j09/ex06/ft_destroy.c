/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 00:02:57 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 15:15:25 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void ft_destroy(char ***factory)
{
	int i;
	int j;

	i = 0;
	while (factory[i])
	{
		j = 0;
		while (factory[i][j])
		{
			free(factory[i][j]);
		}
		free(factory[i]);
	}
}
