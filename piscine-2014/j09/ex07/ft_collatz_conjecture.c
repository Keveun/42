/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 01:14:53 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 01:51:41 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base != 1)
	{
		if (!(base % 2))
			return (ft_collatz_conjecture(base / 2) + 1);
		else
			return (ft_collatz_conjecture((base * 3) + 1) + 1);
	}
	return (0);
}
