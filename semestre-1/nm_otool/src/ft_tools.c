/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 17:22:38 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/20 23:21:56 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

unsigned int		ft_rev_int(unsigned int num)
{
	unsigned int	swapped;

	swapped = ((num >> 24) & 0xff) |
		((num << 8) & 0xff0000) |
		((num >> 8) & 0xff00) |
		((num << 24) & 0xff000000);
	return (swapped);
}
