/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:48:55 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/05 19:33:23 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (*s1 != '\0')
		*str++ = *s1++;
	*str = '\0';
	return (str - len);
}
