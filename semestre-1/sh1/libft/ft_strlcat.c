/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:49:24 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/05 19:34:06 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dstlen;
	size_t		srclen;
	size_t		value;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i + dstlen < size - 1)
	{
		if (i < size)
			dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	value = srclen + ((dstlen < size) ? dstlen : size);
	return (value);
}
