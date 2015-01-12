/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/12 20:59:27 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "limits.h"
#define TEST "test"

int		main(int argc, char **argv)
{
	char	*test;
	int		val1;
	int		val2;

	test = TEST;
	val1 = 0;
	val2 = 0;
	if (argc > 1)
	{
		val1 = printf(argv[1], 0);
		printf("\nval1: %d\n", val1);
		val2 = ft_printf(argv[1], 0);
		printf("\nval2: %d\n", val2);
		// val1 = printf("{%10R}");
		// val2 = ft_printf(argv[1], 260, -9999L, test);
		// val2 = ft_printf("{%10R}");
	}
	return (0);
}
