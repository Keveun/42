/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 17:58:21 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/02 18:48:45 by kperreau         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int i;

	nb--;
	while (1)
	{
		nb++;
		if (nb <= 3)
		{
			if (nb > 1)
				break ;
			else
				continue;
		}
		if (!(nb % 2) || !(nb % 3))
			continue;
		i = 5;
		while (i < ft_sqrt(nb) + 1)
		{
			if (!(nb % i) || !(nb % (i + 2)))
				continue;
			i += 6;
		}
		break ;
	}
	return (nb);
}
