/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:19:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:19:33 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rotate(int *pile, int n, int display)
{
	int		i;

	if (display == 1)
		write(1, "ra ", 3);
	else if (display == 2)
		write(1, "rb ", 3);
	i = 0;
	while (--n)
	{
		ft_swap(pile + i, pile + i + 1);
		++i;
	}
}

void		ft_push_b(int *a, int *b, int pb)
{
	write(1, "pb ", 3);
	b[pb] = *a;
	*a = 0;
}

void		ft_push_a(int *a, int *b, int pa)
{
	if (pa)
		write(1, "pa ", 3);
	else
		write(1, "pa", 3);
	a[pa] = *b;
	*b = 0;
}
