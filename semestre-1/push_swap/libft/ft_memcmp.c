/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:37:31 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/09 13:10:07 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uchar;

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*(t_uchar*)s1 != *(t_uchar*)s2)
			return (*(t_uchar*)s1 - *(t_uchar*)s2);
		s1++;
		s2++;
	}
	return (0);
}
