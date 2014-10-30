/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 16:28:02 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/01 21:42:03 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_sort_integer_table(int *tab, int size)
{
	int	i;
	int	copy_tab;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			copy_tab = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = copy_tab;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
