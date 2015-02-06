/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 02:53:16 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/31 02:53:18 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 11) || c == 32 || c == 13)
		return (1);
	return (0);
}