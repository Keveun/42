/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/03 22:11:14 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "limits.h"
#define TEST "test"

int		main(int argc, char **argv)
{
	char	c;
	char	*test;

	c = 'a';
	test = TEST;
	if (argc > 1)
	{
		printf(argv[1], LONG_MAX, 9999, test);
		printf("\n");
		ft_printf(argv[1], LONG_MAX, 9999, test);
	}
	return (0);
}