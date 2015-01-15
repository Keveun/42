/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:08:05 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 19:08:13 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i++] = str[len];
		str[len--] = temp;
	}
}
