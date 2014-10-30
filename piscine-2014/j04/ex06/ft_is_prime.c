/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 13:52:54 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/02 17:57:13 by kperreau         ###   ########.fr       */
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

int ft_is_prime(int nb)
{
	int	i;

	if (nb <= 3)
		return (nb > 1);
	if (!(nb % 2) || !(nb % 3))
		return (0);
	i = 5;
	while (i < ft_sqrt(nb) + 1)
	{
		if (!(nb % i) || !(nb % (i + 2)))
			return (0);
		i += 6;
	}
	return (1);
}
