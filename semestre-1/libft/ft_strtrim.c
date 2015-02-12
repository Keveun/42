/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:06:02 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/09 17:24:11 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	start;
	size_t	end;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup((char*)s));
	len = ft_strlen(s);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	end = len - 1;
	while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if ((str = ft_strsub(s, start, end - start + 1)) == NULL)
		return (NULL);
	return (str);
}
