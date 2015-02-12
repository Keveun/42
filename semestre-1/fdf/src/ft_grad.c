/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 17:41:30 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/28 21:17:10 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_gap(int x, int y)
{
	int		gap;

	gap = x - y;
	return (gap);
}

double	ft_ratio(int gap)
{
	double	ratio;

	ratio = (gap > 0) ? 255 / (double)gap : 0;
	return (ratio);
}
