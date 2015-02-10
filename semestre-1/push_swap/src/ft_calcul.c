/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 02:23:14 by Kevin             #+#    #+#             */
/*   Updated: 2015/02/10 02:23:23 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_get_minpos(int *a, int n)
{
	int		min;
	int		pos;
	int		minpos;

	min = *a;
	pos = 0;
	minpos = 0;
	while (n--)
	{
		if (*a < min)
		{
			min = *a;
			minpos = pos;
		}
		++a;
		++pos;
	}
	return (minpos);
}

// static void		ft_test(int *a, int size)
// {
	// while (size--)
		// printf("a: %d\n", *a++);
	// printf("\n");
// }

static void		ft_finish(int *a, int *b, int n)
{
	ft_push_a(a, b, n);
	ft_rotate(b, n + 1, 0);
}

int				ft_calc(int *a, int *b, int n)
{
	int		na;
	int		nb;
	int		best;

	na = n;
	nb = 0;
	// ft_test(a, n);
	while (nb < n)
	{
		best = ft_get_minpos(a, na);
		while (best--)
			ft_rotate(a, na, 1);
		ft_push_b(a, b, n - nb - 1);
		ft_rotate(a, na, 0);
		--na;
		++nb;
	}
	na = n;
	while (na--)
		ft_finish(a, b, na);
	write(1, "\n" ,1);
	// ft_test(a, n);
	return (0);
}