/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/05 00:11:13 by Kevin            ###   ########.fr       */
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

int				ft_dectohex(long n, int maxlen, int up)
{
	int		i;
	int		rem;
	char	hex[20];
	int		len;

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
	len = ft_strlen(hex);
	if (maxlen != -1 && len > maxlen)
		write(1, hex , maxlen);
	else
		ft_putstr(hex);
	return ((len > maxlen) ? maxlen : len);
}