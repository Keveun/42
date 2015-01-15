/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/16 00:27:54 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "limits.h"
#include <locale.h>
#define TEST "test"

int		main(int argc, char **argv)
{
	//int		val1;
	int		val2;

	setlocale(LC_ALL, "en_US.UTF-8");
	//val1 = 0;
	val2 = 0;
	if (argc > 1)
	{
		//val1 = printf(argv[1], 5762, 945, L'米', 'a', "abc", L"米米", L"我是一只猫。");
		//printf("\nval1: %d\n", val1);
		//val2 = ft_printf(argv[1], 5762, 945, L'米', 'a', "abc", L"米米", L"我是一只猫。");
		val2 = ft_printf(argv[1], "un super test", NULL, "Le leet c'est vraiment trop drole !");
		printf("\nval2: %d\n", val2);
	}
	return (0);
}
