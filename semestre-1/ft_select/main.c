/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:11:25 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/20 20:18:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_init_infos(t_infos *infos, int argc)
{
	infos->lastid = 0;
	infos->cursor.x = 0;
	infos->cursor.y = 0;
	infos->nbr_selected = 0;
	infos->nbr_print = 0;
	infos->start = 0;
	infos->pos_col = 0;
	infos->redisp = 0;
	infos->nbr_visible = argc;
	infos->nbr_args = argc;
	infos->nbr_rargs = argc;
	return (0);
}

t_infos			*ft_singleton(void)
{
	static t_infos infos;

	return (&infos);
}

static void		ft_sig(void)
{
	signal(SIGINT, ft_sig_int);
	signal(SIGTSTP, ft_sig_stop);
	signal(SIGCONT, ft_sig_cont);
}

int				main(int argc, char **argv)
{
	char		*tname;
	t_infos		*infos;

	infos = ft_singleton();
	ft_sig();
	if (ft_init_infos(infos, argc - 1) == -1)
		return (-1);
	if ((infos->fd = open(ttyname(STDIN_FILENO), O_WRONLY)) == -1)
		return (-1);
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
