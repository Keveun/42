/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 19:01:18 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/16 11:38:15 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	char	str1[2];
	char	str2[2];
	int		hour1;
	int		hour2;

	if (hour < 0 || hour > 23)
		return ;
	hour1 = (hour == 0) ? 12 : hour;
	if (hour > 12)
	{
		hour1 -= 12;
		str1[0] = 'P';
	}
	else
		str1[0] = (hour == 12) ? 'P' : 'A';
	hour2 = hour + 1;
	if (hour2 > 12)
	{
		hour2 -= 12;
		str2[0] = (hour2 == 12) ? 'A' : 'P';
	}
	else
		str2[0] = (hour2 == 12) ? 'P' : 'A';
	printf("THE FOLLOWING TAKES PLACE BETWEEN");
	printf(" %d.00 %s.M. AND %d.00 %s.M.\n", hour1, str1, hour2, str2);
}
