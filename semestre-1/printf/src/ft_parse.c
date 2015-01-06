/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/06 21:24:36 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_parse(char *str, int len, t_vars *vars)
{
	t_options	opt;
	char		*c;
	int			(**pf)(t_options *, va_list *, int *);

	if (!(c = ft_strchr(FT_TYPES, str[len])))
		return ;
	pf = vars->f;
	opt.type = c - FT_TYPES;
	opt.flags = ft_flag(FT_FLAGS, str, len);
	opt.len = ft_len(str, len);
	opt.precise = ft_precise(str, len);
	opt.modif = ft_modif(str, len);
	
	(*pf[opt.type])(&opt, &vars->ap, &vars->ret);
	/*printf("[%.*s]\n", len, str);
	printf("flags: %d\n", opt.flags);
	printf("len: %d\n", opt.len);
	printf("precise: %d\n", opt.precise);
	printf("Modif: %d\n", opt.modif);
	printf("type: %d\n", opt.type);*/
}
