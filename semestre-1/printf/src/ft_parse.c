/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/11 19:18:36 by kperreau         ###   ########.fr       */
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
	int			(**pf)(t_options *, va_list *, int *);

	opt.flags = ft_flag(FT_FLAGS, str, len);
	opt.len = ft_len(str, len, &vars->ap);
	opt.precise = ft_precise(str, len, &vars->ap);
	opt.modif = ft_modif(str, len);
	opt.zero = ft_zero(str);
	if ((c = ft_strchr(FT_TYPES, str[len])))
	{
		pf = vars->f;
		opt.type = c - FT_TYPES;
		(*pf[opt.type])(&opt, &vars->ap, &vars->ret);
	}
	else
		vars->ret += ft_notype(str + len, &opt);
	/*printf("[%.*s]\n", len, str);
	printf("flags: %d\n", opt.flags);
	printf("len: %d\n", opt.len);
	printf("precise: %d\n", opt.precise);
	printf("Modif: %d\n", opt.modif);
	printf("type: %d\n", opt.type);*/
}