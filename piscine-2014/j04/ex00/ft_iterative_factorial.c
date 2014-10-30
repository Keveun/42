/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 21:56:06 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/02 03:23:30 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_factorial(int nb)
{
	int i;

	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	i = nb;
	nb = 1;
	while (i > 0)
	{
		nb *= i;
		i--;
	}
	return (nb);
}
