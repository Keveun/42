/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:07:44 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/07 16:17:21 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*val;
	char	*str;

	if ((val = (void*)malloc(sizeof(void) * size)) == NULL)
		return (NULL);
	str = val;
	while (size-- > 0)
		*str++ = 0;
	return (val);
}
