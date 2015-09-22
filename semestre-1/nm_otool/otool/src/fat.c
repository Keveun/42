/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 17:06:07 by kperreau          #+#    #+#             */
/*   Updated: 2015/09/22 17:06:09 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

unsigned int		ft_rev_int(unsigned int i)
{
	unsigned int c;

	c = ((i & 0x000000ff) << 24u |
		(i & 0x0000ff00) << 8u |
		(i & 0x00ff0000) >> 8u |
		(i & 0xff000000) >> 24u);
	return (c);
}

static void			treatment_fat(T_SEG_CMD_64 *segment, char *ptr, char *name)
{
	int				j;
	T_SEC_64		*sect;

	sect = (struct section_64*)((void*)segment + sizeof(*segment));
	j = -1;
	if (segment->cmd == LC_SEGMENT_64)
	{
		while (++j < (int)segment->nsects)
		{
			if (sect[j].sectname && !ft_strcmp(sect[j].sectname, SECT_TEXT))
				print_hex_64(ptr, &sect[j], name, 0);
		}
	}
	segment = (void *)segment + segment->cmdsize;
}

static void			treatment_data_fat(T_SEG_CMD_64 *segment, char *ptr,
		char *name)
{
	int				j;
	T_SEC_64		*sect;

	sect = (struct section_64*)((void*)segment + sizeof(*segment));
	j = -1;
	if (segment->cmd == LC_SEGMENT_64)
	{
		while (++j < (int)segment->nsects)
		{
			if (sect[j].sectname && !ft_strcmp(sect[j].sectname, SECT_DATA))
				print_hex_data_64(ptr, &sect[j], name, -1);
		}
	}
	segment = (void *)segment + segment->cmdsize;
}

static void			handle_fat(char *ptr, T_FAT_HEADER *header, char *name)
{
	int							i;
	struct load_command			*lc;
	struct segment_command_64	*segment;

	i = 0;
	lc = (void *)ptr + sizeof(struct mach_header_64);
	while (i++ < (int)ft_rev_int(header->nfat_arch))
	{
		segment = (struct segment_command_64*)lc;
		treatment_fat(segment, ptr, name);
		lc = (void *)lc + lc->cmdsize;
	}
	if ((get_flags(0) >> (ft_strchr(FLAGS, 'd') - FLAGS)) & 1)
	{
		i = 0;
		lc = (void *)ptr + sizeof(struct mach_header_64);
		while (i++ < (int)ft_rev_int(header->nfat_arch) + 1)
		{
			segment = (struct segment_command_64*)lc;
			treatment_data_fat(segment, ptr, name);
			lc = (void *)lc + lc->cmdsize;
		}
	}
}

void				fat(char *ptr, T_FAT_HEADER *header, char *name)
{
	struct fat_arch			*arch;
	char					*newptr;
	int						i;

	arch = (void*)ptr + sizeof(*header);
	if ((get_flags(0) >> (ft_strchr(FLAGS, 'f') - FLAGS)) & 1)
		fat_header(header, arch);
	i = -1;
	while (++i < (int)ft_rev_int(header->nfat_arch))
	{
		if (ft_rev_int(arch->cputype) == CPU_TYPE_X86_64)
			break ;
		arch = (void*)arch + sizeof(*arch);
	}
	newptr = (void*)ptr + ft_rev_int(arch->offset);
	if (*(unsigned int*)newptr == MH_MAGIC_64)
		handle_fat(newptr, header, name);
	else if (!ft_strncmp(newptr, ARMAG, SARMAG))
		handle_lib(newptr, name, ft_rev_int(arch->size));
}
