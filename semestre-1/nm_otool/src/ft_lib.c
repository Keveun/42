/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 22:27:06 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/24 18:08:10 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		ft_sub_lib(char *str)
{
	if (*(unsigned int*)str == MH_MAGIC_64)
		ft_handle64(str, (struct mach_header_64*)str);
	else
		ft_handle(str, (struct mach_header*)str);
}

static void		ft_print_name(char *file, void *str, int add)
{
	t_mach_header_64	*header64;
	t_mach_header		*header32;
	int					n;
	void				*ptr;

	ptr = str + add;
	if (*(unsigned int*)ptr == MH_MAGIC_64)
	{
		header64 = (struct mach_header_64*)ptr;
		n = header64->ncmds;
	}
	else
	{
		header32 = (struct mach_header*)ptr;
		n = header32->ncmds;
	}
	if (n > 1)
		ft_printf("\n%s(%s):\n", file, str);
}

void			ft_lib(char *ptr, char *file, int size)
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
	while (++i < slib.arr_len && slib.str - ptr < size)
	{
		ar = (struct ar_hdr*)slib.str;
		slib.str += sizeof(struct ar_hdr);
		ft_print_name(file, slib.str, ft_atoi(ft_strchr(ar->ar_name, '/') + 1));
		slib.str += ft_atoi(ft_strchr(ar->ar_name, '/') + 1);
		ft_sub_lib(slib.str);
		slib.str += ft_atoi(ar->ar_size) - ft_atoi(ft_strchr(ar->ar_name, '/')\
			+ 1);
	}
}
