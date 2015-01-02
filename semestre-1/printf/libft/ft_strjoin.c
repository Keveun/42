/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:48:36 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/12 16:16:04 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	lens1 = (s1) ? ft_strlen(s1) : 0;
	lens2 = (s2) ? ft_strlen(s2) : 0;
	if ((str = ft_strnew(lens1 + lens2)) == NULL)
		return (NULL);
	if (s1)
		str = ft_strcpy(str, s1);
	if (s2)
		str = ft_strcat(str, s2);
	return (str);
}
