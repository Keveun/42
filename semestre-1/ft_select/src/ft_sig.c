/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 17:38:22 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/19 18:42:04 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_sig_int(int sig)
{
	t_infos		*infos;

	(void)sig;
	infos = ft_singleton();
	ft_reset_term(&infos->term, infos);
	exit(0);
}

void		ft_sig_stop(int sig)
{
	// t_infos		*infos;
	// char		cp[2];

	(void)sig;
	// if (isatty(1))
	// {
		// infos = ft_singleton();
		// cp[0] = infos->term.c_cc[VSUSP];
		// cp[1] = '\0';
		// ft_reset_term(&infos->term, infos);
		// ioctl(0, TIOCSTI, cp);
		// ft_putstr("\b\b\033[0J");
		// signal(SIGTSTP, SIG_DFL);
	// }
}

void		ft_sig_cont(int sig)
{
	t_infos		*infos;

	(void)sig;
	infos = ft_singleton();
	ft_init_term(&infos->term, infos);
	ft_display(infos);
}
