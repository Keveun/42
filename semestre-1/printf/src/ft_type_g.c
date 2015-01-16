/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:33:33 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/16 00:35:39 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_write_g(t_options *opt, char *s, char *s2)
{
	int		len;

	len = ft_strlen(s);
	if (opt->precise != -1)
		opt->precise = ft_leetnlen(s2, opt->precise);
	len = (opt->precise != -1 && len > opt->precise) ? opt->precise : len;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	write(1, s, len);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len != -1 && len < opt->len) ? opt->len : len;
	return (len);
}

int			ft_g(t_options *opt, va_list *ap, int *ret)
{
	char		*s;
	char		*leet;
	int			value;

	s = NULL;
	if ((s = va_arg(*ap, char *)))
	{
		leet = ft_leet(s);
		value = ft_write_g(opt, leet, s);
		free(leet);
	}
	else
	{
		leet = ft_strdup("(^/(_)11)");
		value = ft_write_g(opt, leet, s);
		free(s);
	}
	*ret += value;
	return (value);
}
