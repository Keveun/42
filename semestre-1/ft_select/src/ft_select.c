/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 19:53:56 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_reset_term(t_termios *term, t_infos *infos)
{
	char	*res;

	ft_putstr_fd("\033[?1049l\033[0m", infos->fd);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	if ((res = tgetstr("ve", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_my_outc);
	return (0);
}

int				ft_init_term(t_termios *term, t_infos *infos)
{
	char	*res;

	ft_putstr_fd("\033[?1049h\033[H", infos->fd);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, (char*)&infos->size) < 0)
		ft_putstr_fd("Erreur TIOCGEWINSZ\n", 2);
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	if (((infos->mr = tgetstr("mr", NULL)) == NULL) ||
		((infos->me = tgetstr("me", NULL)) == NULL) ||
		((infos->us = tgetstr("us", NULL)) == NULL) ||
		((infos->ue = tgetstr("ue", NULL)) == NULL) ||
		((infos->cm = tgetstr("cm", NULL)) == NULL) ||
		((infos->cl = tgetstr("cl", NULL)) == NULL))
		return (-1);
	tputs(infos->cl, 0, ft_my_outc);
	if ((res = tgetstr("vi", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_my_outc);
	return (0);
}

static int		ft_check_key(int key, t_infos *infos)
{
	if (key == K_DEL || key == K_BACKSPACE)
	{
		if (ft_delete(infos) == -1)
			return (-1);
	}
	else if (key == K_EXIT || key == K_RETURN)
		return (-1);
	else if (key == K_RESET)
		ft_reset(infos);
	return (0);
}

void			ft_select(int argc, char **argv, t_infos *infos)
{
	int		key;

	if (ft_init_term(&infos->term, infos) != -1)
	{
		signal(SIGWINCH, ft_resize);
		infos->args = ft_args(argc, argv);
		infos->reset = ft_args(argc, argv);
		ft_display(infos);
		while (1)
		{
			key = 0;
			read(0, &key, sizeof(int));
			ft_moove(infos, key);
			if (ft_check_key(key, infos) == -1)
				break ;
		}
		ft_reset_term(&infos->term, infos);
		if (key == K_RETURN)
			ft_out(infos);
	}
}
