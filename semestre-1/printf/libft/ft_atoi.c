/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:29:37 by kperreau          #+#    #+#             */
/*   Updated: 2014/11/09 13:14:26 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_whitespace(char c)
{
	if (c == ' ' ||
		c == '\t' ||
		c == '\n' ||
		c == '\r' ||
		c == '\v' ||
		c == '\f')
		return (1);
	return (0);
}

long			ft_atoi(const char *str)
{
	size_t	is_negative;
	long	value;

	is_negative = 0;
	value = 0;
	while (ft_check_whitespace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		is_negative = 1;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		value = value * 10 + *str - '0';
		str++;
	}
	if (is_negative)
		value = -value;
	return (value);
}
