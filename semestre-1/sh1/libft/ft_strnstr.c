/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:10:05 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/08 21:03:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;
	size_t		i;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	len = ft_strlen(s2);
	while (i + len <= n && *s1 != '\0')
	{
		if (!ft_memcmp(s1++, s2, len))
			return ((char*)s1 - 1);
		i++;
	}
	return (NULL);
}
