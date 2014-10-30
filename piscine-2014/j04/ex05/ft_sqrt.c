/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 10:48:18 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/02 13:32:44 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int nb)
{
	int value;
	int perfect;

	if (nb == 1)
		return (1);
	value = 1;
	while (value <= nb / 2)
	{
		perfect = value * value;
		if (perfect == nb)
			return (value);
		value++;
	}
	return (0);
}
