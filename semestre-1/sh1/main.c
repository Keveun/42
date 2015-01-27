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

#include "sh1.h"

static int		ft_init_sh1(pid_t *father)
{
	*father = fork();
	return (1);
}

int				main(int argc, char **argv)
{
	pid_t		father;

	ft_init_sh1(&father);
	while (1)
	{
		if (father > 0)
		{
			wait(NULL);
		}
		if (father == 0)
		{
			(void)argc;
			execve("/bin/ls", argv, NULL);
		}
	}
	return (0);
}
