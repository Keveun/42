/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:22:03 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/06 21:59:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_x(t_options *opt, va_list *ap, int *ret)
{
	unsigned int	p;

	p = va_arg(*ap, unsigned int);
	*ret += ft_dectohex(p, -1, 0);
	return (0);
}

int			ft_x2(t_options *opt, va_list *ap, int *ret)
{
	unsigned int	p;

	p = va_arg(*ap, unsigned int);
	*ret += ft_dectohex(p, -1, 1);
	return (0);
}

int			ft_o(t_options *opt, va_list *ap, int *ret)
{
	unsigned long	n;

	n = va_arg(*ap, unsigned int);
	n = ft_dectooctal(n);
	ft_putnbrul(n);
	*ret += ft_digitlen(n);
	return (0);
}

int			ft_o2(t_options *opt, va_list *ap, int *ret)
{
	unsigned long	n;

	n = va_arg(*ap, long);
	n = ft_dectooctal(n);
	ft_putnbrul(n);
	*ret += ft_digitlen(n);
	return (0);
}

int			ft_u2(t_options *opt, va_list *ap, int *ret)
{
	unsigned long	n;

	n = va_arg(*ap, long);
	ft_putnbrul(n);
	*ret += ft_digitlen(n);
	return (0);
}
