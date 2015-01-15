/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:13:23 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 19:35:58 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_write_b(t_options *opt, char *bin, long n)
{
	int		len;
	int		temp;

	temp = (n || opt->precise) ? ft_strlen(bin) : 0;
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->precise || n)
		write(1, bin, temp);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	return ((opt->len > len) ? opt->len : len);
}

int				ft_b(t_options *opt, va_list *ap, int *ret)
{
	long	n;
	char	bin[50];

	if (1 << opt->modif & 30)
		n = va_arg(*ap, long);
	else if (!opt->modif)
		n = (short)va_arg(*ap, int);
	else if (opt->modif == 5)
		n = (char)va_arg(*ap, int);
	else
		n = va_arg(*ap, int);
	n = ft_dectobin(bin, n);
	*ret += ft_write_b(opt, bin, n);
	return (0);
}
