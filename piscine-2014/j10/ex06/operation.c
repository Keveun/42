/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 12:03:26 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/09 18:33:16 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_add(int a, int b)
{
	return (a + b);
}

int	ft_sub(int a, int b)
{
	return (a - b);
}

int	ft_mul(int a, int b)
{
	return (a * b);
}

int	ft_mod(int a, int b)
{
	return (a % b);
}

int	ft_div(int a, int b)
{
	return ((b) ? a / b : 0);
}
