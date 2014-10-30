/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 15:41:06 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 15:47:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (tab[i])
	{
		j = 0;
		count = 0;
		while (tab[j])
		{
			if (tab[i] == tab[j])
				count++;
			j++;
		}
		if (count == 1)
			return (tab[i]);
		i++;
	}
	return (0);
}
