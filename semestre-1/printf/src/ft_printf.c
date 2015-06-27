/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:22:03 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 20:40:40 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_parse_var(char *str, t_vars *vars)
{
	int		i;

	i = 0;
	while (str[i] && (ft_isdigit(str[i]) || ft_strchr(FT_PARSE, str[i])))
		++i;
	if (str[i])
	{
		ft_parse(str, i, vars);
		++i;
	}
	return (i);
}

static void		ft_init_f(int (**f)(t_options *, va_list *, int *))
{
	f[0] = ft_s;
	f[1] = ft_s2;
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
	f[13] = ft_c2;
	f[14] = ft_b;
	f[15] = ft_r;
	f[16] = ft_g;
}

static int		ft_sub_printf(char *str, t_vars *vars)
{
	char	*begin;

	begin = str;
	vars->ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			vars->ret += str - begin;
			if (vars->ret > 0)
				write(1, begin, str - begin);
			str += ft_parse_var(str + 1, vars) + 1;
			if (vars->ret == -1)
				return (-1);
			begin = str;
		}
		else
			++str;
	}
	vars->ret += ft_strlen(begin);
	ft_putstr(begin);
	va_end(vars->ap);
	return (0);
}

int				ft_printf(const char *format, ...)
{
	t_vars		vars;
	int			ret;

	if (format == NULL)
		return (-1);
	va_start(vars.ap, format);
	ft_init_f(vars.f);
	ret = (ft_sub_printf((char*)format, &vars) != -1) ? vars.ret : -1;
	return (ret);
}
