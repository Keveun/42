/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:17:52 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/04 10:47:55 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] > 126 || str[i] < 33))
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	char test[] = " ";
	printf("%d", ft_str_is_printable(test));
	return (1);
}
