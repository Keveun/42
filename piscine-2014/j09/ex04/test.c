/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 22:07:20 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/11 22:24:03 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_rot42(char *str)
{
	int		i;
	int		j;

	i = 1;
	while (i < 43)
	{
		j = 0;
		while (str[j])
		{
			if ((str[j] >= 'a' && str[j] <= 'z') ||
				(str[j] >= 'A' && str[j] <= 'Z'))
			{
				if (str[j] == 'z')
					str[j] = 'a';
				else if (str[j] == 'Z')
					str[j] = 'A';
				else
					str[j] += 1;
			}
			j++;
		}
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("test: %s\n", ft_rot42(argv[1]));
	return (0);
}
