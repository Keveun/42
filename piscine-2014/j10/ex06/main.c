/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 10:47:28 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/09 18:33:14 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

typedef	int	(*t_opp)(int, int);
t_opp	opptab[6];

void	ft_showresult(char **argv, char *operator, int(*opptab)(int, int))
{
	opptab[0] = &ft_sub;
	opptab[1] = &ft_add;
	opptab[2] = &ft_mul;
	opptab[3] = &ft_div;
	opptab[4] = &ft_mod;
	if (argv[2][0] == operator[0])
		opptab[0](ft_atoi(argv[1]), ft_atoi(argv[3]));
}

int		main(int argc,char **argv)
{
	char	operator[6];

	//operator[0] = '-';
	//operator[1] = '+';
	//operator[2] = '*';
	//operator[3] = '/';
	//operator[4] = '%';
	//operator[5] = '\0';
	opptab[0] = &ft_sub;
	opptab[1] = &ft_add;
	opptab[2] = &ft_mul;
	opptab[3] = &ft_div;
	opptab[4] = &ft_mod;
	if (argc == 4)
		ft_showresult(argv, operator, (*opptab));
	return (0);
}
