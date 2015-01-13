/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/13 20:07:16 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_write_c(t_options *opt, wint_t c)
{
	int		len;

	len = 1;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	write(1, &c, 1);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len != -1 && len < opt->len) ? opt->len : len;
	return (len);
}

int			ft_c(t_options *opt, va_list *ap, int *ret)
{
	wint_t	c;

	if (opt->modif == 1)
		c = va_arg(*ap, wint_t);
	else
		c = (char)va_arg(*ap, int);
	*ret += ft_write_c(opt, c);
	return (0);
}

int			ft_c2(t_options *opt, va_list *ap, int *ret)
{
	if (opt->modif == 5)
		opt->modif = -1;
	else
		opt->modif = 1;
	opt->type = 12;
	return (ft_c(opt, ap, ret));
}
