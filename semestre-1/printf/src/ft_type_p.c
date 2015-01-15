/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:22:03 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 19:04:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_write_p(t_options *opt, char *hex, unsigned long n)
{
	int		len;
	int		temp;

	if (opt->len)
		opt->len -= 2;
	if (opt->precise == -1 && opt->zero)
		opt->precise = opt->len;
	temp = (n || opt->precise) ? ft_strlen(hex) : 0;
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	write(1, "0x", 2);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->precise || n)
		write(1, hex, temp);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len > len) ? opt->len : len;
	return (len + 2);
}

int				ft_p(t_options *opt, va_list *ap, int *ret)
{
	unsigned long	n;
	char			hex[20];

	n = va_arg(*ap, unsigned long);
	ft_dectohex(hex, n, 0);
	*ret += ft_write_p(opt, hex, n);
	return (0);
}
