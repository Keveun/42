/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:18:50 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:19:02 by kperreau         ###   ########.fr       */
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
