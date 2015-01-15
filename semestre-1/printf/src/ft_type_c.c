/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 19:06:41 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_write_c(t_options *opt, wint_t c)
{
	int				len;
	int				bytes;
	int				i;
	unsigned char	mask[4];

	bytes = ft_utfclen(c);
	len = bytes;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	ft_to_utf8(c, bytes, mask);
	i = 0;
	while (i < bytes)
		write(1, &(mask[i++]), 1);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len != -1 && len < opt->len) ? opt->len : len;
	return (len);
}

int			ft_c(t_options *opt, va_list *ap, int *ret)
{
	wint_t	c;
	int		value;

	if (opt->modif == 1)
		c = va_arg(*ap, wint_t);
	else
		c = (char)va_arg(*ap, int);
	if ((value = ft_write_c(opt, c)) > 0)
		*ret += value;
	return (value);
}

int			ft_c2(t_options *opt, va_list *ap, int *ret)
{
	opt->modif = 1;
	opt->type = 12;
	return (ft_c(opt, ap, ret));
}
