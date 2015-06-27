/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:35:02 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/09 17:29:50 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*temp;

	if (size > SIZE_MAX - 1)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	temp = str;
	size++;
	while (size-- > 0)
		*str++ = '\0';
	return (temp);
}
