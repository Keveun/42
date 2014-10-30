/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 10:31:15 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 11:38:50 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

t_bool	open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = TRUE;
	return (TRUE);
}

t_bool	close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
	return (TRUE);
}

t_bool	is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	return (door->state == OPEN);
}

t_bool	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	return (door->state == CLOSE);
}
