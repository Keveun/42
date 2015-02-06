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

static void		ft_read_file(t_list **lenv, char *s)
{
	char	*line;
	int		fd;

	if ((fd = open(s, O_RDONLY)) != -1)
	{
		line = NULL;
		while (get_next_line(fd, &line) > 0)
		{
			ft_parse_stdin(line, lenv);
			free(line);
			line = NULL;
		}
		if (line)
		{
			ft_parse_stdin(line, lenv);
			free(line);
		}
		close(fd);
	}
	else
		ft_printerror(s, NULL, 3);
}

int				main(int argc, char **argv, char **env)
{
	t_list	*lenv;

	signal(SIGINT, SIG_IGN);
	lenv = ft_tab_to_list(env);
	if (argc > 1)
		ft_read_file(&lenv, argv[1]);
	ft_shell(&lenv);
	return (0);
}
