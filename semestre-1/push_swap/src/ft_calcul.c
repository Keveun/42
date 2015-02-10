/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:17:27 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:18:01 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_get_minpos(int *a, int n)
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

static void		ft_test(int *a, int *b, int size, int max)
{
	int		nb;

	nb = max - size;
	if (max)
	{
		write(1, "\na: ", 4);
		while (size--)
		{
			ft_putnbr(*a++);
			if (size)
				write(1, " ", 1);
		}
		write(1, "\nb: ", 4);
		while (nb--)
		{
			ft_putnbr(*b++);
			if (size)
				write(1, " ", 1);
		}
		write(1, "\n\n", 2);
	}
}

static void		ft_finish(int *a, int *b, int n, int max)
{
	ft_push_a(a, b, n);
	ft_rotate(b, n + 1, 0);
	if (max)
		ft_test(a + n, b, max - n, max);
}

void			ft_calc(int *a, int *b, int n, int debug)
{
	int		na;
	int		nb;
	int		best;

	na = n;
	nb = 0;
	while (nb < n)
	{
		best = ft_get_minpos(a, na);
		while (best--)
		{
			ft_rotate(a, na, 1);
			ft_test(a, b + na, na, (debug) ? n : 0);
		}
		ft_push_b(a, b, n - nb++ - 1);
		ft_rotate(a, na--, 0);
		ft_test(a, b + na, na, (debug) ? n : 0);
	}
	na = n;
	while (na--)
		ft_finish(a, b, na, (debug) ? n : 0);
	if (!debug)
		write(1, "\n", 1);
}
