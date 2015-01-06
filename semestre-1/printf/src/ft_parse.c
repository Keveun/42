/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/05 00:11:13 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_parse(char *str, int len, va_list *ap, \
					int (*f[14])(t_options *, va_list *ap))
{
	t_options	opt;

	if (!(opt.type = (int)ft_strchr(FT_TYPES, str[len])))
		return ;
	opt.type -= (int)FT_TYPES;
	opt.flags = ft_flag(FT_FLAGS, str, len);
	opt.len = ft_len(str, len);
	opt.precise = ft_precise(str, len);
	opt.modif = ft_modif(str, len);
	(*f[opt.type])(&opt, ap);
	/*printf("[%.*s]\n", len, str);
	printf("flags: %d\n", opt.flags);
	printf("len: %d\n", opt.len);
	printf("precise: %d\n", opt.precise);
	printf("Modif: %d\n", opt.modif);
	printf("type: %d\n", opt.type);*/
}
