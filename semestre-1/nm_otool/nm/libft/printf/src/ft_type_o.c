/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 19:05:21 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_write_o(t_options *opt, char *oct, unsigned long n)
{
	int		len;
	int		temp;

	temp = (n || opt->precise) ? ft_strlen(oct) : 0;
	temp += ((opt->flags & 8 && (n || !temp)) ? 1 : 0);
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->flags & 8 && (n || !opt->precise))
		write(1, "0", 1);
	if (opt->precise || n)
		write(1, oct, temp);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	return ((opt->len > len) ? opt->len : len);
}

int				ft_o(t_options *opt, va_list *ap, int *ret)
{
	unsigned long	n;
	char			oct[30];

	if (1 << opt->modif & 30)
		n = va_arg(*ap, unsigned long);
	else if (!opt->modif)
		n = (unsigned short)va_arg(*ap, unsigned int);
	else if (opt->modif == 5)
		n = (unsigned char)va_arg(*ap, unsigned int);
	else
		n = va_arg(*ap, unsigned int);
	n = ft_dectooctal(oct, n);
	*ret += ft_write_o(opt, oct, n);
	return (0);
}

int				ft_o2(t_options *opt, va_list *ap, int *ret)
{
	opt->modif = 1;
	opt->type = 6;
	return (ft_o(opt, ap, ret));
}
