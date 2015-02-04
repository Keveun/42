/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:39:09 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/27 23:14:55 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_init_sh1(pid_t *father)
{
	return (1);
}

static void		ft_sighandler(int signum)
{
	// if (signum & (SIGINT | SIGQUIT))
		// exit(1);
}

int				main(int argc, char **argv, char **env)
{
	signal(SIGINT, SIG_IGN);
	(void)argc;
	(void)argv;
	// ft_init_sh1(&father);
	ft_shell(env);
	return (0);
}
