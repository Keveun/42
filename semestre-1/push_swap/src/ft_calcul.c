/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:17:27 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/11 20:49:17 by kperreau         ###   ########.fr       */
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

void			ft_test(int *a, int *b, int size, int max)
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

static void		ft_finish(t_data *pile, int *b, int max)
{
	ft_push_a(pile->a, b, pile->nb, pile);
	if (max)
		ft_test(pile->a + pile->nb, b + 1, max - pile->nb, max);
}

static void		ft_opti(t_data *pile)
{
	int			best;
	double		mid;
	int			count;

	best = ft_get_minpos(pile->a, pile->na) + 1;
	mid = pile->na / 2;
	count = ((mid >= 1 && best > mid) ? pile->na - best + 1 : best - 1);
	while (count--)
	{
		if (best > mid)
			ft_rev_rotate(pile->a, pile->na, 1, pile);
		else
			ft_rotate(pile->a, pile->na, 1, pile);
		ft_test(pile->a, pile->b + 1, pile->na, (pile->debug) ? pile->n : 0);
	}
}

void			ft_calc(t_data *pile)
{
	while (pile->nb < pile->n)
	{
		if (ft_is_sort(pile->a, pile->na))
			break ;
		if (ft_check_sa(pile))
			continue ;
		ft_opti(pile);
		if (ft_is_sort(pile->a, pile->na))
			break ;
		ft_push_b(pile->a, pile->b, pile->n - pile->nb++ - 1, pile);
		ft_rotate(pile->a, pile->na--, 0, pile);
		ft_rev_rotate(pile->b, pile->nb + 1, 0, pile);
		ft_test(pile->a, pile->b + 1, pile->na, (pile->debug) ? pile->n : 0);
	}
	while (pile->na != pile->n && pile->na--)
		ft_rotate(pile->a, pile->n, 0, pile);
	while (pile->nb--)
		ft_finish(pile, ++pile->b, (pile->debug) ? pile->n : 0);
	if (pile->opti)
	{
		write(1, "Total: ", 7);
		ft_putnbr(pile->count);
	}
	if (!pile->debug || !pile->count)
		write(1, "\n", 1);
}
