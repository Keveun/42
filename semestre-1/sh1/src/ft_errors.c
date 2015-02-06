/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 05:10:36 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/28 05:10:45 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_printerror(char *s1, char *s2, int type)
{
	write(2, "-", 1);
	write(2, NAME, ft_strlen(NAME));
	if (s1)
	{
		write(2, ": ", 2);
		write(2, s1, ft_strlen(s1));
	}
	if (type == 1)
		write(2, " : command not found\n", 21);
	else if (type == 2)
		write(2, " : Permission denied\n", 21);
	else if (type == 3)
		write(2, ": No such file or directory\n", 28);
	else if (type == 4)
	{
		write(2, ": ", 2);
		if (s2)
			write(2, s2, ft_strlen(s2));
		write(2, ": Not a directory\n", 18);
	}
}