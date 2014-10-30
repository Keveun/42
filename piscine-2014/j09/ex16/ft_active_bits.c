/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 11:46:26 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 12:12:36 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	int count;

	count = 0;
	while (value)
	{
		value &= value - 1;
		count++;
	}
	return (count);
}
