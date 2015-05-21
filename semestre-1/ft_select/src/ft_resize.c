/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 19:53:26 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_resize(int sig)
{
	t_infos		*infos;
	char		*res;
	int			size;

	if ((res = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(res, 0, ft_my_outc);
	(void)sig;
	infos = ft_singleton();
	size = infos->size.ws_col * infos->size.ws_row;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, (char*)&infos->size) < 0)
		ft_putstr_fd("Erreur TIOCGEWINSZ\n", 2);
	infos->cursor.x = 0;
	infos->cursor.y = 0;
	if (infos->size.ws_row * infos->size.ws_col < size)
		infos->lastid = infos->start;
	ft_display(infos);
}
