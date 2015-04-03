/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:11:25 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/30 20:41:14 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_init_infos(t_infos *infos, int argc)
{
	infos->cursor.x = 0;
	infos->cursor.y = 0;
	infos->nbr_args = argc;
}

t_infos			*ft_singleton(void)
{
	static t_infos infos;

	return (&infos);
}

int				main(int argc, char **argv)
{
	char		*tname;
	t_infos		*infos;

	infos = ft_singleton();
	ft_init_infos(infos, argc - 1);
	if ((tname = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, tname) == ERR)
		return (-1);
	if (tcgetattr(0, &infos->term) == -1)
		return (-1);
	if (argc > 1)
		ft_select(argc - 1, argv + 1, infos);
	else
		ft_putstr_fd("Too few arguments.\n", 2);
	return (0);
}
