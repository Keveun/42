/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:48:46 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/03 09:52:49 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int j;

	if (!src[0])
		return (dest);
	j = 0;
	while (dest[j])
		j++;
	i = 0;
	while (i < nb)
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}
