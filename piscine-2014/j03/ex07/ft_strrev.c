/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 01:18:48 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/02 15:09:08 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	copy_str;
	int		i;
	int		j;

	i = 0;
	if (!str[0] || str[0] == '\0')
		return (str);
	while (str[i + 1])
		i++;
	j = 0;
	while (j != i)
	{
		copy_str = str[i];
		str[i] = str[j];
		str[j] = copy_str;
		i--;
		j++;
	}
	return (str);
}
