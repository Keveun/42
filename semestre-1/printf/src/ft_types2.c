/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:22:03 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/04 23:52:22 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_x(t_options *opt, va_list *ap)
{
	long	p;

	p = va_arg(*ap, long);
	return (ft_dectohex(p, -1, 0));
}

int			ft_x2(t_options *opt, va_list *ap)
{
	long	p;

	p = va_arg(*ap, long);
	return (ft_dectohex(p, -1, 1));
}

int			ft_o(t_options *opt, va_list *ap)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	ft_putnbr(ft_dectooctal(n));
	return (0);
}

int			ft_o2(t_options *opt, va_list *ap)
{
	unsigned long	n;

	n = va_arg(*ap, long);
	ft_putnbrul(ft_dectooctal(n));
	return (0);
}

int			ft_u2(t_options *opt, va_list *ap)
{
	unsigned long	n;

	n = va_arg(*ap, long);
	ft_putnbrul(n);
	return (0);
}
