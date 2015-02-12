/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:00:05 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/09 13:13:38 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n-- > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
	}
	return (0);
}
