/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:29:19 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/11 21:10:41 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_write_s(t_options *opt, char *s)
{
	int		len;

	len = ft_strlen(s);
	len = (opt->precise != -1 && len > opt->precise) ? opt->precise : len;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	write(1, s, len);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len != -1 && len < opt->len) ? opt->len : len;
	return (len);
}

int			ft_s(t_options *opt, va_list *ap, int *ret)
{
	char	*s;

	if (opt->modif == 1)
		s = (char*)va_arg(*ap, wchar_t *);
	else
		s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		*ret += 6;
		return (0);
	}
	*ret += ft_write_s(opt, s);
	return (0);
}


int			ft_s2(t_options *opt, va_list *ap, int *ret)
{
	opt->modif = 1;
	opt->type = 0;
	return (ft_c(opt, ap, ret));
}
