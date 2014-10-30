/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 15:28:55 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/01 16:26:42 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(char *str)
{
	int is_negative;
	int value;

	is_negative = 0;
	value = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		is_negative = 1;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = value * 10 + *str - '0';
		str++;
	}
	if (is_negative)
		value = -value;
	return (value);
}
