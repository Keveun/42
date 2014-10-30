/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gservett <gservett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 00:45:08 by gservett          #+#    #+#             */
/*   Updated: 2014/09/14 21:34:07 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	loop_square(int x, int y, int i2);

int		main(int argc, char **argv)
{
	int i;
	int j;
	int k;

	//colle(5, 3);
	if (argc == 4)
	{
		i = argv[1][0] - 48;
		j = argv[2][0] - 48;
		k = argv[3][0] - 48;
		loop_square(i, j, k);
	}
	return (0);
}
