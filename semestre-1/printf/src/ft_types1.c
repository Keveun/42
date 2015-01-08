/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/08 23:45:22 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_s(t_options *opt, va_list *ap, int *ret)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (0);
	}
	len = ft_strlen(s);
	len = (opt->precise != -1 && len > opt->precise) ? opt->precise : len;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, ret, len);
	write(1, s, len);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, ret, len);
	len = (opt->len != -1 && len < opt->len) ? opt->len : len;
	*ret += len;
	return (0);
}

int			ft_d(t_options *opt, va_list *ap, int *ret)
{
	long	n;
	int		len;
	int		temp;

	if (opt->type == 8 || opt->type == 9)
		n = va_arg(*ap, unsigned int);
	else
		n = va_arg(*ap, int);
	temp = ft_digitlen(n);
	len = (opt->precise > temp) ? opt->precise : temp;
	if (opt->len > temp && !(opt->flags & 1))
		ft_putspace(opt, ret, len);
	if (n < 0)
		write(1, "-", 1);
	if (opt->precise > temp)
		ft_putzero(opt, ret, temp);
	ft_putnbr((n < 0) ? -n : n);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, ret, len);
	len = (opt->len > len) ? opt->len : len;
	*ret += ((n < 0) ? 1 : 0) + len;
	return (0);
}

int			ft_d2(t_options *opt, va_list *ap, int *ret)
{
	long	n;
	int		len;

	n = va_arg(*ap, long);
	ft_putnbr(n);
	len = ft_digitlen(n);
	*ret += len;
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
