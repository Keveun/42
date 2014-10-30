/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 19:49:19 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/18 22:56:05 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

static void		ft_init_data(t_data *data)
{
	data->offset = -1;
	data->len = 0;
	data->bsq[2] = 0;
}

int		main(int argc, char **argv)
{
	int		i;
	t_data	data;

	ft_init_data(&data);
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
			ft_show_map(argv[i], &data, 1);
	}
	else
		ft_show_map("stdin", &data, 0);
	return (0);
}