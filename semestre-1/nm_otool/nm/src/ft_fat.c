/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 23:08:11 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/26 13:05:46 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_fat_handle(char *ptr, t_fat_header *header, char *file)
{
	struct fat_arch		*arch;
	char				*newptr;
	int					i;

	arch = (void*)ptr + sizeof(*header);
	i = -1;
	while (++i < (int)ft_rev_int(header->nfat_arch))
	{
		if (ft_rev_int(arch->cputype) == CPU_TYPE_X86_64)
			break ;
		arch = (void*)arch + sizeof(*arch);
	}
	newptr = (void*)ptr + ft_rev_int(arch->offset);
	if (*(unsigned int*)newptr == MH_MAGIC_64)
		ft_handle64(newptr, (struct mach_header_64*)newptr);
	else if (!ft_strncmp(newptr, ARMAG, SARMAG))
		ft_lib(newptr, file, ft_rev_int(arch->size));
}
