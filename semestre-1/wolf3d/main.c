/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:39:09 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 17:56:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_wolf_mlx(t_mlx *mx)
{
	ft_loop(mx);
	ft_display(mx, &mx->map, &mx->v);
	mlx_hook(mx->win, 2, 1, &key_press_hook, mx);
	mlx_hook(mx->win, 3, 2, &key_release_hook, mx);
	mlx_loop_hook(mx->mlx, &key_loop_hook, mx);
	mlx_expose_hook(mx->win, expose_hook, mx);
	mlx_loop(mx->mlx);
}

int				main(int argc, char **argv)
{
	t_mlx	mx;
	int		type;

	type = 0;
	if (argc > 2 && !ft_strcmp(argv[1], "-swag"))
	{
		type = 1;
		++argv;
		--argc;
	}
	if (argc != 2)
		ft_putstr_fd("Wrong args number.\n", 2);
	else if (!type && ft_init_mlx(&mx))
		ft_putstr_fd("mlx_init Fail\n", 2);
	else if (ft_init_map(&mx.map, argv[1]) == -1)
		ft_putstr_fd("Missing files.\n", 2);
	else if (ft_init_vars(&mx.v, &mx.map) == -1)
		ft_putstr_fd("Start point not found.\n", 2);
	else if (type == 1)
		ft_wolf_shell(&mx);
	else
		ft_wolf_mlx(&mx);
	return (0);
}
