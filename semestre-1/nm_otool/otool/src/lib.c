/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-pach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:51:14 by mde-pach          #+#    #+#             */
/*   Updated: 2015/09/21 16:40:53 by mde-pach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void		ft_sub_lib(char *str)
{
	if (*(unsigned int*)str == MH_MAGIC_64)
		handle_64(str, str, 1);
	else
		handle(str, str, 1);
}

void			handle_lib(char *ptr, char *file, int size)
{
	struct ranlib	*lib;
	struct ar_hdr	*ar;
	int				i;
	t_lib			slib;

	slib.start = (void*)ptr + sizeof(struct ar_hdr) + SARMAG + 20;
	slib.st_len = *(unsigned int*)slib.start / sizeof(struct ranlib);
	lib = (struct ranlib*)(slib.start + 4);
	slib.str = (void*)lib + slib.st_len * sizeof(struct ranlib) + 4;
	slib.arr_len = *(unsigned int*)(slib.str - 4);
	slib.str += slib.arr_len;
	i = -1;
	ft_printf("Archive : %s\n", file);
	while (++i < (int)slib.arr_len && slib.str - ptr < size)
	{
		ar = (struct ar_hdr*)slib.str;
		slib.str += sizeof(struct ar_hdr);
		ft_printf("%s(%s):\n", file, slib.str);
		slib.str += ft_atoi(ft_strchr(ar->ar_name, '/') + 1);
		ft_sub_lib(slib.str);
		slib.str += ft_atoi(ar->ar_size) - ft_atoi(ft_strchr(ar->ar_name, '/')\
			+ 1);
	}
}
