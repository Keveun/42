/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:49:24 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/05 19:33:38 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		i;
	size_t		len;

	if (!*s2)
		return (s1);
	len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[i + len] = s2[i];
		i++;
	}
	s1[i + len] = '\0';
	return (s1);
}
