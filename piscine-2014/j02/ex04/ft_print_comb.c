/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/28 18:26:16 by kperreau          #+#    #+#             */
/*   Updated: 2014/08/30 10:23:29 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	write_number(int first_number, int second_number, int third_number)
{
	ft_putchar(third_number + 48);
	ft_putchar(second_number + 48);
	ft_putchar(first_number + 48);
	if (third != 7)
	{
		ft_putchar(' ');
		ft_putchar(',');
	}
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			while (k < 10)
			{
				if (i != j && i != k && k != j && k > j && j > i)
				{
					write_number(k, j, i);
				}
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
