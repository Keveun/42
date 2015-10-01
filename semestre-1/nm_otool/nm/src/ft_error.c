/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 16:06:44 by kperreau          #+#    #+#             */
/*   Updated: 2015/09/23 18:44:29 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int			ft_error_options(char msg)
{
	ft_putstr_fd("error: ft_nm: invalid argument -", 2);
	ft_putchar_fd(msg, 2);
	ft_putstr_fd("\nusage: ft_nm [-gpjru] [file ...]\n", 2);
	return (-1);
}

int			ft_error_file(char *msg)
{
	ft_putstr_fd("Error: ft_nm: can't open file: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" (No such file or directory).\n", 2);
	return (-1);
}
