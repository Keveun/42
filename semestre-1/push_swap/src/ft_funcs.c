/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:19:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/11 20:30:09 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		ft_rotate(int *pile, int n, int display, t_data *spile)
{
	int		i;

	if (display && !spile->opti)
	{
		if (display == 1)
			write(1, "ra ", 3);
		else if (display == 2)
			write(1, "rb ", 3);
	}
	if (display)
		++spile->count;
	i = 0;
	while (--n)
	{
		ft_swap(pile + i, pile + i + 1);
		++i;
	}
}

void		ft_rev_rotate(int *pile, int n, int display, t_data *spile)
{
	if (display && !spile->opti)
	{
		if (display == 1)
			write(1, "rra ", 4);
		else if (display == 2)
			write(1, "rrb ", 4);
	}
	if (display)
		++spile->count;
	while (--n)
		ft_swap(pile + n, pile + n - 1);
}

void		ft_push_b(int *a, int *b, int pb, t_data *pile)
{
	(void)pb;
	++pile->count;
	if (!pile->opti)
		write(1, "pb ", 3);
	*b = *a;
	*a = 0;
}

void		ft_push_a(int *a, int *b, int pa, t_data *pile)
{
	if (!pile->opti)
	{
		if (pa)
			write(1, "pa ", 3);
		else
			write(1, "pa", 3);
	}
	++pile->count;
	a[pa] = *b;
	*b = 0;
}

void		ft_swap_a(int *a, int pa, t_data *pile)
{
	int		temp;

	if (!pile->opti)
	{
		if (pa)
			write(1, "sa ", 3);
		else
			write(1, "sa", 3);
	}
	++pile->count;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}
