/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 17:06:29 by kperreau          #+#    #+#             */
/*   Updated: 2015/09/22 17:06:30 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void			treatment_64(struct segment_command_64 *segment,
								char *ptr, char *name, int lib)
{
	int					j;
	struct section_64	*section;

	section = (struct section_64*)((void*)segment + sizeof(*segment));
	j = -1;
	if (segment->cmd == LC_SEGMENT_64)
	{
		while (++j < (int)segment->nsects)
		{
			if (!ft_strcmp(section[j].sectname, SECT_TEXT))
				print_hex_64(ptr, &section[j], name, lib);
		}
	}
	segment = (void *)segment + segment->cmdsize;
}

static void			treatment_64_data(struct segment_command_64 *segment,
								char *ptr, char *name, int lib)
{
	int					j;
	struct section_64	*section;

	section = (struct section_64*)((void*)segment + sizeof(*segment));
	j = -1;
	if (segment->cmd == LC_SEGMENT_64)
	{
		while (++j < (int)segment->nsects)
		{
			if (!ft_strcmp(section[j].sectname, SECT_DATA))
				print_hex_data_64(ptr, &section[j], name, lib);
		}
	}
	segment = (void *)segment + segment->cmdsize;
}

void				handle_64(char *ptr, char *name, int lib)
{
	int							i;
	struct mach_header_64		*header;
	struct load_command			*lc;
	struct segment_command_64	*segment;

	i = 0;
	header = (struct mach_header_64 *)ptr;
	lc = (void *)ptr + sizeof(struct mach_header_64);
	while (i++ < (int)header->ncmds)
	{
		segment = (struct segment_command_64*)lc;
		treatment_64(segment, ptr, name, lib);
		lc = (void *)lc + lc->cmdsize;
	}
	if ((get_flags(0) >> (ft_strchr(FLAGS, 'd') - FLAGS)) & 1)
	{
		i = 0;
		lc = (void *)ptr + sizeof(struct mach_header_64);
		while (i++ < (int)header->ncmds)
		{
			segment = (struct segment_command_64*)lc;
			treatment_64_data(segment, ptr, name, -1);
			lc = (void *)lc + lc->cmdsize;
		}
	}
}
