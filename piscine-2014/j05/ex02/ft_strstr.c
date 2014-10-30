/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 00:47:11 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/03 16:57:36 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (to_find[0] == '\0' || !(*to_find))
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i - j]);
			j++;
		}
		else if (j)
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (0);
}
