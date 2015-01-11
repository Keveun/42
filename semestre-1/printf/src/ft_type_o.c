/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/11 22:57:55 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_write_o(t_options *opt, unsigned long long n)
{
	int		len;
	int		temp;

	temp = ((opt->flags & 8) ? 1 : 0) + ft_nbrlen2(n);
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->flags & 8 && n)
		write(1, "0", 2);
	ft_putnbrul(n);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len > len) ? opt->len : len;
	return (len);
}

int			ft_o(t_options *opt, va_list *ap, int *ret)
{
	unsigned long long	n;

	if (opt->modif == 1)
		n = va_arg(*ap, unsigned long);
	else
		n = va_arg(*ap, unsigned int);
	n = ft_dectooctal(n);
	*ret += ft_write_o(opt, n);
	return (0);
}

int			ft_o2(t_options *opt, va_list *ap, int *ret)
{
	opt->modif = 1;
	opt->type = 6;
	return (ft_o(opt, ap, ret));
}
