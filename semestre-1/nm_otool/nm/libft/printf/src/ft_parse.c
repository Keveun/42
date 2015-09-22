/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/20 23:03:02 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_notype(char *str, t_options *opt)
{
	int		len;

	len = (opt->len > 1) ? opt->len : 1;
	opt->type = 0;
	if (!(opt->flags & 1))
		ft_putspace(opt, 1, 0);
	write(1, str, 1);
	if (opt->flags & 1)
		ft_putspace(opt, 1, 0);
	return (len);
}

void			ft_parse(char *str, int len, t_vars *vars)
{
	t_options	opt;
	char		*c;
	int			(*pf)(t_options *, va_list *, int *);

	opt.flags = ft_flag(FT_FLAGS, str, len);
	opt.len = ft_len(str, len, &vars->ap);
	opt.flags |= (opt.len >= 0) ? 0 : 1;
	opt.len = (opt.len >= 0) ? opt.len : -opt.len;
	opt.precise = ft_precise(str, len, &vars->ap);
	opt.modif = ft_modif(str, len);
	opt.zero = ft_zero(str);
	if ((c = ft_strchr(FT_TYPES, str[len])))
	{
		opt.type = c - FT_TYPES;
		pf = *(vars->f + opt.type);
		if ((*pf)(&opt, &vars->ap, &vars->ret) == -1)
			vars->ret = -1;
	}
	else
		vars->ret += ft_notype(str + len, &opt);
}
