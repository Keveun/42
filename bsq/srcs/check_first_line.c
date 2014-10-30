/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 16:15:51 by kperreau          #+#    #+#             */
/*   Updated: 2014/10/09 03:11:30 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

static int		ft_is_printable(char *str, int len)
{
	int i;

	i = len - 2;
	while (++i < len)
		if (str[i] > 126 || str[i] < 33)
			return (0);
	return (1);
}

static int		ft_str_is_numeric(char *str)
{
	while (*str)
		if (!(*str >= '0' && *(str++) <= '9'))
			return (0);
	return (1);
}

static int		ft_atoi(char *str)
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

int				ft_check_first_line(char *str, t_data *data)
{
	char	*temp;
	int		i;

	data->hlen = ft_strlen_n(str, 0);
	if (data->hlen < 4 || data->hlen > 15 || str[data->hlen] != '\n' ||
		(temp = (char*)malloc(sizeof(char) * (data->hlen - 3))) == NULL)
		return (0);
	temp[data->hlen - 3] = '\0';
	data->total_lines = ft_atoi(ft_strncpy(temp, str, (data->hlen - 3)));
	if (!ft_str_is_numeric(temp) ||
		!ft_is_printable(str, data->hlen) ||
		(data->total_lines < 1))
		return (0);
	free(temp);
	i = -1;
	while (++i < 3)
		data->str[i] = str[data->hlen - 3 + i];
	if ((data->str[0] == data->str[1]) ||
		(data->str[0] == data->str[2]) ||
		(data->str[1] == data->str[2]))
		return (0);
	return ((data->hlen) ? data->hlen + 1 : 0);
}