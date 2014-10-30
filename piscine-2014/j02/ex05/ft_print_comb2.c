/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/28 18:26:16 by kperreau          #+#    #+#             */
/*   Updated: 2014/08/29 09:50:29 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	write_number(int first_number, int second_number)
{
	ft_putchar((second_number / 10) + 48);
	ft_putchar((second_number % 10) + 48);
	ft_putchar(' ');
	ft_putchar((first_number / 10) + 48);
	ft_putchar((first_number % 10) + 48);
	if (first_number < 99)
	{
		ft_putchar(' ');
		ft_putchar(',');
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		while (j < 100)
		{
			if (i < j)
			{
				write_number(j, i);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
