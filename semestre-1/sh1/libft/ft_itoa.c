/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:17:06 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/08 13:16:11 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_count(long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(long n)
{
	char	*str;
	char	*strtemp;
	size_t	negative;
	size_t	i;

	negative = (n < 0) ? 1 : 0;
	n = (negative) ? n : -n;
	i = (n) ? ft_itoa_count(n) : 1;
	if ((str = ft_strnew(i + negative)) == NULL)
		return (NULL);
	strtemp = str;
	if (negative)
		*str++ = '-';
	str += i - 1;
	while (i-- > 0)
	{
		*str-- = -(n % 10) + 48;
		n /= 10;
	}
	return (strtemp);
}
