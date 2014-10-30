/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 23:05:16 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 14:15:13 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_bouton(int i, int j, int k)
{
	int		value[3];
	int		copy_value;
	int		l;

	l = 0;
	value [0] = i;
	value[1] = j;
	value[2] = k;
	while (l < 2)
	{
		if (value[l] > value[l + 1])
		{
			copy_value = value[l + 1];
			value[l + 1] = value[l];
			value[l] = copy_value;
			l = 0;
		}
		else
			l++;
	}
	return (value[1]);
}
