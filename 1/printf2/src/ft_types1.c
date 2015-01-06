/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:22:03 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/04 23:52:22 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_s(t_options *opt, va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (0);
	}
	ft_putstr(s);
	return (0);
}

int			ft_d(t_options *opt, va_list *ap)
{
	long	n;

	if (opt->type == 8 || opt->type == 9)
		n = va_arg(*ap, unsigned int);
	else
		n = va_arg(*ap, int);
	ft_putnbr(n);
	return (0);
}

int			ft_d2(t_options *opt, va_list *ap)
{
	long	n;

	n = va_arg(*ap, long);
	ft_putnbr(n);
	return (0);
}

int			ft_c(t_options *opt, va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar(c);
	return (0);
}

int			ft_p(t_options *opt, va_list *ap)
{
	long	p;

	p = va_arg(*ap, long);
	write(1, "0x", 2);
	return (ft_dectohex(p, -1, 0));
}