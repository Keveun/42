/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 02:52:28 by Kevin             #+#    #+#             */
/*   Updated: 2015/02/10 02:52:39 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void		ft_test(int *a, int size)
// {
	// while (size--)
		// printf("a: %d\n", *a++);
	// printf("\n");
// }

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