/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:22:03 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/07 22:17:20 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_parse_var(char *str, t_vars *vars)
{
	int		i;

	i = 0;
	while (str[i] && (!ft_isalpha(str[i]) || ft_strchr(FT_MODIF, str[i])))
		++i;
	if (ft_strchr(FT_TYPES, str[i]))
		++i;
	ft_parse(str, i - 1, vars);
	return (i);
}

static int		ft_init_f(int (**f)(t_options *, va_list *, int *))
{
	f[0] = ft_s;
	f[2] = ft_p;
	f[3] = ft_d;
	f[4] = ft_d2;
	f[5] = ft_d;
	f[6] = ft_o;
	f[7] = ft_o2;
	f[8] = ft_u;
	f[9] = ft_u2;
	f[10] = ft_x;
	f[11] = ft_x2;
	f[12] = ft_c;
}

int				ft_printf(const char *format, ...)
{
	char		*str;
	char		*begin;
	t_vars		vars;

	if (format == NULL)
		return (-1);
	va_start(vars.ap, format);
	str = (char*)format;
	ft_init_f(vars.f);
	begin = str;
	vars.ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			vars.ret += str - begin - 1;
			write(1, begin, str - begin - 1);
			if(*str != '%')
				str += ft_parse_var(str, &vars);
			begin = str;
		}
		++str;
	}
	vars.ret += ft_strlen(begin);
	ft_putstr(begin);
	va_end(vars.ap);
	return (vars.ret);
}
