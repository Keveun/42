/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:51:58 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/07 22:13:16 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONG_MAX 9223372036854775807L
#define LONG_MIN (-LONG_MAX - 1L)

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		if (n == LONG_MIN)
		{
			ft_putstr("-9223372036854775808");
			return ;
		}
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(48 + n);
	}
}
