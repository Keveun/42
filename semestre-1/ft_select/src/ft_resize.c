/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/27 15:48:52 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_size_ok(t_infos *infos)
{
	int		i;

	i = -1;
	while (++i < infos->nbr_args)
	{
		if (infos->args[i].len > infos->size.ws_col)
		{
			infos->error = 1;
			return (-1);
		}
	}
	infos->error = 0;
	return (0);
}

void			ft_resize(int sig)
{
	t_infos		*infos;
	char		*res;
	int			size;

	(void)sig;
	infos = ft_singleton();
	if ((res = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(res, 0, ft_my_outc);
	size = infos->size.ws_col * infos->size.ws_row;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, (char*)&infos->size) < 0)
		ft_putstr_fd("Erreur TIOCGEWINSZ\n", 2);
	if (ft_size_ok(infos) != -1)
	{
		infos->cursor.x = 0;
		infos->cursor.y = 0;
		if (infos->size.ws_row * infos->size.ws_col < size)
			infos->lastid = infos->start;
		ft_display(infos);
	}
	else
		ft_resize_error(infos);
}
