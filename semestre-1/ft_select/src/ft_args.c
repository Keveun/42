/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/30 20:39:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_args			*ft_args(int argc, char **argv)
{
	t_args	*args;
	t_args	*begin;

	if ((args = malloc(sizeof(t_args) * (argc + 1))) == NULL)
		return (NULL);
	begin = args;
	while (argc--)
	{
		args->len = ft_strlen(*argv);
		args->visible = 1;
		args->selected = 0;
		(args++)->str = *argv++;
		// printf("test: %s\n", (args-1)->str);
	}
	return (begin);
}
