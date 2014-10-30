/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 10:28:31 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 11:05:42 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_door.h"

int main(void)
{
	t_door door;

	open_door(&door);
	if (is_door_close(&door))
		open_door(&door);
	if (is_door_open(&door))
		close_door(&door);
	if (door.state == OPEN)
		close_door(&door);
	return (EXIT_SUCCESS);
}
