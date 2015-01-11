/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/11 19:21:38 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_write_d(t_options *opt, long long n)
{
	int		len;
	int		temp;
	int		issigned;

	issigned = (n < 0 || opt->flags & 6) ? 1 : 0;
	temp = ft_nbrlen2((n < 0) ? -n : n);
	len = ((opt->precise > temp) ? opt->precise : temp) + issigned;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, n);
	if (issigned)
		ft_putsigned(opt->flags, n);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	ft_putnbrul((n < 0) ? -n : n);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, n);
	len = (opt->len > len) ? opt->len : len;
	return (len);
}

int			ft_d(t_options *opt, va_list *ap, int *ret)
{
	long long	n;

	if (opt->type == 5)
		opt->type = 3;
	if (opt->modif == 1)
		n = va_arg(*ap, long);
	else
		n = va_arg(*ap, int);
	*ret += ft_write_d(opt, n);
	return (0);
}

int			ft_d2(t_options *opt, va_list *ap, int *ret)
{
	opt->modif = 1;
	opt->type = 3;
	return (ft_d(opt, ap, ret));
}
