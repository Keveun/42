/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:09:31 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/09 14:49:17 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uchar;

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar	*ptr;

	if (s == NULL || !n)
		return (NULL);
	ptr = (t_uchar*)s;
	while (n-- > 1 && *ptr != (t_uchar)c)
		ptr++;
	return (*ptr == (t_uchar)c ? (void*)ptr : NULL);
}
