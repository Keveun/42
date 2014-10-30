/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 23:22:38 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/02 03:10:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
	int i;
	int total;

	if (power < 0 || (nb == 0 && power != 0))
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	total = nb;
	while (i < power - 1)
	{
		total *= nb;
		i++;
	}
	return (total);
}
