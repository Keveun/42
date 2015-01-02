/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:10:58 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/02 22:08:21 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int		signe;
	int		space;
	int		type;
	int		min;
	int		max;
	int		option;
}				t_flags;

int				ft_printf(const char *format, ...);
#endif
