/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-pach <mde-pach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 11:28:57 by mde-pach          #+#    #+#             */
/*   Updated: 2015/09/21 16:48:11 by mde-pach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void		ft_error_object(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": is not an object file\n", 2);
}

void		ft_error_open(char *s, char *s1)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": can't open file: ", 2);
	ft_putendl_fd(s1, 2);
}
