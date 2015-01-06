/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:06:42 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/09 13:08:58 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uchar;

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (src != NULL)
	{
		while (n-- > 0)
		{
			*(char*)dst++ = *(char*)src++;
			if (*(char*)(src - 1) == c)
				return (dst);
		}
	}
	return (NULL);
}
