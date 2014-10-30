/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 08:53:59 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/06 18:01:12 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

int		ft_is_valide(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) != 9)
		return (0);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}
