/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:53:47 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/15 19:02:39 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putspace(t_options *opt, int len, long long n)
{
	char	*str;
	int		size;
	int		i;
	char	c;

	size = (opt->len > len) ? opt->len - len : 0;
	if (opt->type == 3 && n < 0 && opt->precise == -1 && opt->zero \
		&& !(opt->flags & 1))
	{
		opt->precise += opt->len;
		return ;
	}
	if ((str = (char*)malloc(sizeof(char*) * size)) == NULL)
		return ;
	if (opt->type >= 2 && opt->type <= 11 && opt->precise != -1)
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

void		ft_putzero(t_options *opt, int len)
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

void		ft_putsigned(int flags, long long n)
{
	if (n < 0)
		write(1, "-", 1);
	else if (flags & 2)
		write(1, "+", 1);
	else
		write(1, " ", 1);
}

int			ft_nbrlen2(unsigned long n)
{
	return ((n > 9) ? ft_nbrlen2(n / 10) + 1 : 1);
}

int			ft_searchpoint(char *str, int len)
{
	while (str[len] != '.' && len >= 0)
		--len;
	if (str[len] != '.')
		len = -1;
	return (len);
}
