/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:18:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/11 20:40:25 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_toint(char **tab, t_data *pile)
{
	long	temp;
	int		count;
	int		*begin;
	int		n;

	begin = pile->a;
	count = 0;
	n = pile->n;
	while (n--)
	{
		if (ft_strlen(*tab) > 11)
			return (-1);
		temp = ft_atoi(*tab++);
		if ((temp > 2147483647 || temp < -2147483648) ||
			(count && ft_isdouble(begin, count, temp)))
			return (-1);
		*pile->a++ = (int)temp;
		++count;
	}
	pile->a = begin;
	return (0);
}

static int	ft_convert(char **tab, t_data *pile)
{
	if (!ft_isnumbers(tab, pile->n) || ft_toint(tab, pile) == -1)
		return (-1);
	return (0);
}

static void	ft_init_pile(t_data *pile)
{
	pile->debug = 0;
	pile->count = 0;
	pile->opti = 0;
	pile->nb = 0;
}

void		ft_push_swap(char **tab, int n)
{
	t_data	pile;

	ft_init_pile(&pile);
	if (!ft_strcmp(*tab, "-v") || !ft_strcmp(*tab, "-i"))
	{
		if (!ft_strcmp(*tab++, "-v"))
			pile.debug = 1;
		else
			pile.opti = 1;
		--n;
	}
	if (pile.debug && n < 1)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (((pile.a = (int*)malloc(sizeof(int) * n)) == NULL) ||
		((pile.b = (int*)malloc(sizeof(int) * n)) == NULL))
		return ;
	pile.n = n;
	pile.na = n;
	if (ft_convert(tab, &pile) != -1)
		ft_calc(&pile);
	else
		write(2, "Error\n", 6);
}
