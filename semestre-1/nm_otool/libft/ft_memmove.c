/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:11:44 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/05 19:34:33 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	if ((temp = (void*)malloc(sizeof(void) * len + 1)) == NULL)
		return (NULL);
	temp = ft_memcpy(temp, src, len);
	dst = ft_memcpy(dst, temp, len);
	free(temp);
	return (dst);
}
