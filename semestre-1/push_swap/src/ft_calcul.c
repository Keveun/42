/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:17:27 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/11 22:28:23 by kperreau         ###   ########.fr       */
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
	if (max)
		ft_test(a + n, b + 1, max - n, max);
}

static void		ft_opti(int *a, int *b, int na, int debug)
{
	int			best;
	static int	n = 0;
	double		mid;
	int			count;

	if (!n)
		n = na;
	best = ft_get_minpos(a, na) + 1;
	mid = na / 2;
	count = ((mid >= 1 && best > mid) ? na - best + 1 : best - 1);
	while (count--)
	{
		if (best > mid)
			ft_rev_rotate(a, na, 1);
		else
			ft_rotate(a, na, 1);
		ft_test(a, b + 1, na, (debug) ? n : 0);
	}
}

void			ft_calc(int *a, int *b, int n, int debug)
{
	int		na;
	int		nb;

	na = n;
	nb = 0;
	while (nb < n)
	{
		if (ft_is_sort(a, na))
			break ;
		ft_opti(a, b, na, debug);
		if (ft_is_sort(a, na))
			break ;
		ft_push_b(a, b, n - nb++ - 1);
		ft_rotate(a, na--, 0);
		ft_rev_rotate(b, nb + 1, 0);
		ft_test(a, b + 1, na, (debug) ? n : 0);
	}
	while (na--)
		ft_rotate(a, n, 0);
	na = nb;
	while (na--)
		ft_finish(a, ++b, na, (debug) ? n : 0);
	if (!debug)
		write(1, "\n", 1);
}
