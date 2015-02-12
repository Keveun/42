/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:46:35 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/13 16:02:59 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*temp;

	if ((len < 1 || s == NULL || s[start] == '\0') ||
		(str = ft_strnew(len)) == NULL)
		return (NULL);
	temp = str;
	s += start;
	while (len-- > 0)
		*str++ = *s++;
	return (temp);
}
