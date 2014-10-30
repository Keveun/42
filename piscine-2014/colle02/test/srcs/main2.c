/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gservett <gservett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 00:45:08 by gservett          #+#    #+#             */
/*   Updated: 2014/09/14 21:20:04 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	loop_square(int x, int y);

int		main(int argc, char **argv)
{
	//colle(5, 3);
	if (argc == 4)
	{
		loop_square(20, 10);
	}
	return (0);
}
