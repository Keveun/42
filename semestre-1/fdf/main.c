/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 15:13:01 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/12 20:46:45 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_mlx		mx;

	if (argc == 2)
	{
		mx.map = ft_read_file(argv[1]);
		if (mx.map)
		{
			ft_init_mlx(&mx);
			lx_hook(mx.win, 3, 3, key_hook, &mx);
			mlx_expose_hook(mx.win, expose_hook, &mx);
			mlx_loop(mx.mlx);
		}
		else
			ft_error("Map Error.\n");
	}
	else
		ft_error("Necessite un argument !\n");
	return (0);
}
