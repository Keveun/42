/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:39:31 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/12 14:15:19 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	const char	*temp;

	if (s == NULL)
		return (0);
	temp = s;
	while (*s != '\0')
		s++;
	return (s - temp);
}
