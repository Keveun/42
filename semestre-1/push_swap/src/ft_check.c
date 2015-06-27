/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:18:50 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/11 17:47:45 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_isnumbers(char **tab, int n)
{
	char	*s;

	while (n--)
	{
		s = *tab++;
		while (*s)
		{
			if (s == *(tab - 1) && *s == '-' && ft_isdigit(s[1]))
				;
			else if (!ft_isdigit(*s))
				return (0);
			++s;
		}
	}
	return (1);
}

int			ft_isdouble(int *a, int size, int value)
{
	while (size--)
	{
		if (value == *a++)
			return (1);
	}
	return (0);
}

int			ft_is_sort(int *a, int n)
{
	int		i;

	i = 0;
	while (--n)
	{
		if (a[i] > a[i + 1])
			return (0);
		++i;
	}
	return (1);
}

int			ft_check_sa(t_data *pile)
{
	if (pile->a[0] < pile->a[1])
		return (0);
	ft_swap_a(pile->a, pile->na, pile);
	ft_test(pile->a, pile->b + 1, pile->na, (pile->debug) ? pile->n : 0);
	return (1);
}
