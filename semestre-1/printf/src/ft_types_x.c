/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:22:03 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/06 21:59:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*static int		ft_write_x(t_options *opt, char *hex)
{
	int		len;
	int		temp;

	temp = ft_strlen(hex);
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	write(1, hex, temp);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len > len) ? opt->len : len;
	return (len);
}*/

static int		ft_write_x(t_options *opt, char *hex)
{
	int		len;
	int		temp;

	if (opt->len && opt->flags & 8)
		opt->len -= 2;
	if (opt->precise == -1 && opt->zero && opt->flags & 8)
		opt->precise = opt->len;
	temp = ft_strlen(hex);
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	if (opt->flags & 8)
		write(1, "0x", 2);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	write(1, hex, temp);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len > len) ? opt->len : len;
	return (len + 2);
}

int			ft_x(t_options *opt, va_list *ap, int *ret)
{
	unsigned long long	n;
	char				hex[20];

	if (opt->modif == -1)
		n = va_arg(*ap, unsigned int);
	else if (opt->modif == 1)
		n = va_arg(*ap, unsigned long);
	ft_dectohex(hex, n, (opt->type == 11) ? 1 : 0);
	*ret += ft_write_x(opt, hex);
	return (0);
}

int			ft_x2(t_options *opt, va_list *ap, int *ret)
{
	return (ft_x(opt, ap, ret));
}