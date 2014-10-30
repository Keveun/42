/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 02:03:07 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 04:07:15 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		i++;
	}
	return (str);
}

int		match_sub(char *s1, char *s2)
{
	int	j;
	int i;

	i = 0;
	j = 0;
	while (s1[i] == ' ')
		i++;
	while (s1[i + j] && s2[j] && s1[i + j] == s2[j])
		j++;
	while (s1[i + j] == ' ')
		i++;
	return (!s1[i + j] && !s2[j]);
}

int		match(char *str, char *pattern1, char *pattern2, char *pattern3)
{
	char	*pattern[3];
	int		i;

	pattern[0] = pattern1;
	pattern[1] = pattern2;
	pattern[2] = pattern3;
	i = 0;
	while (i < 3)
	{
		if (match_sub(str, pattern[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_spy(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (match(ft_strlowercase(av[i]), "president", "attack", "powers"))
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		if (ft_spy(argc, argv))
			write(1, "Alert!!!\n", 9);
	return (0);
}
