/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/06 22:00:15 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long	ft_dectooctal(unsigned long n)
{
	unsigned long	rem;
	unsigned long	i;
	unsigned long	octal;
	
	i = 1;
	octal = 0;
	while (n)
	{
		rem = n % 8;
		n /= 8;
		octal += rem * i;
		i *= 10;
	}
	return (octal);
}

int			ft_dectohex(char *hex, unsigned long n, int up)
{
	int		i;
	long	rem;

	i = 0;
	while (n)
	{
		rem = n % 16;
		if (rem >= 10 && rem <= 15)
			hex[i] = (up) ? ft_toupper(FT_HEX[rem % 10]) : FT_HEX[rem % 10];
		else
			hex[i] = rem + '0';
		++i;
		n /= 16;
	}
	hex[i] = '\0';
	ft_strrev(hex);
	return (0);
}
