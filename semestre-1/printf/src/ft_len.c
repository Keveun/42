/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:53:47 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/09 00:00:14 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putspace(t_options *opt, int *ret, int len)
{
	char	*str;
	int		size;
	int		i;
	char	c;

	size = (opt->len > len) ? opt->len - len : 0;
	if (opt->type == 3 && opt->precise == -1 && opt->zero && !(opt->flags & 1))
	{
		opt->precise += opt->len;
		return ;
	}
	if ((str = (char*)malloc(sizeof(char*) * size)) == NULL)
		return ;
	if (opt->type == 3 && opt->precise != -1)
		c = ' ';
	else
		c = (opt->zero && !(opt->flags & 1)) ? '0' : ' ';
	i = 0;
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	write(1, str, size);
	free(str);
}

void		ft_putzero(t_options *opt, int *ret, int len)
{
	char	*str;
	int		size;
	int		i;

	size = ((len < 0) ? 1 : 0) + opt->precise - len;
	if ((str = (char*)malloc(sizeof(char*) * size)) == NULL)
		return ;
	i = 0;
	while (i < size)
		str[i++] = '0';
	str[i] = '\0';
	write(1, str, size);
	free(str);
}

void		ft_putsigned(int flags, int n)
{
	if (n < 0)
		write(1, "-", 1);
	else if (flags & 3)
		write(1, "+", 1);
	else
		write(1, " ", 1);
}