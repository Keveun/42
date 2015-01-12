/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/12 20:44:21 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long	ft_dectooctal(char *oct, unsigned long n)
{
	int				rem;
	unsigned long	i;
	int				j;
	unsigned long	octal;
	
	i = 1;
	j = 0;
	octal = 0;
	if (!n)
		oct[j++] = '0';
	while (n)
	{
		rem = n % 8;
		n /= 8;
		octal += rem * i;
		i *= 10;
		oct[j++] = rem + '0';
	}
	oct[j] = '\0';
	if (j > 1)
		ft_strrev(oct);
	return (octal);
}

int			ft_dectohex(char *hex, unsigned long n, int up)
{
	int		i;
	long	rem;

	i = 0;
	if (!n)
		hex[i++] = '0';
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
	if (i > 1)
		ft_strrev(hex);
	return (0);
}
