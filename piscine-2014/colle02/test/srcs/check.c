/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 16:13:58 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/14 22:45:33 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colle2.h"

int	size(char *buf, int *result)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	while (buf[x] != '\n')
		x++;
	y = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			y++;
		i++;
	}
	result[0] = x;
	result[1] = y;
	return (0);
}
