/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/06 22:02:47 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_s(t_options *opt, va_list *ap, int *ret)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (0);
	}
	ft_putstr(s);
	*ret += ft_strlen(s);
	return (0);
}

int			ft_d(t_options *opt, va_list *ap, int *ret)
{
	long	n;

	if (opt->type == 8 || opt->type == 9)
		n = va_arg(*ap, unsigned int);
	else
		n = va_arg(*ap, int);
	*ret += ((n < 0) ? 1 : 0 ) + ft_digitlen(n);
	ft_putnbr(n);
	return (0);
}

int			ft_d2(t_options *opt, va_list *ap, int *ret)
{
	long	n;

	n = va_arg(*ap, long);
	ft_putnbr(n);
	*ret += ft_digitlen(n);
	return (0);
}

int			ft_c(t_options *opt, va_list *ap, int *ret)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar(c);
	if (c)
		++*ret;
	return (0);
}

int			ft_p(t_options *opt, va_list *ap, int *ret)
{
	long	p;

	p = va_arg(*ap, long);
	write(1, "0x", 2);
	*ret += ft_dectohex(p, -1, 0) + 2;
	return (0);
}
