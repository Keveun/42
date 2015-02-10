/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 22:11:19 by Kevin             #+#    #+#             */
/*   Updated: 2015/02/09 22:11:29 by Kevin            ###   ########.fr       */
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
			if (s == *(tab - 1) && *s == '-')
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