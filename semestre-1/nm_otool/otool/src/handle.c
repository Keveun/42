/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 17:06:39 by kperreau          #+#    #+#             */
/*   Updated: 2015/09/22 17:06:41 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void			treatment(struct segment_command *segment,
							char *ptr, char *name, int lib)
{
	t_section			*section;
	int					j;

	section = (struct section*)((void*)segment + sizeof(*segment));
	j = -1;
	if (segment->cmd == LC_SEGMENT)
	{
		while (++j < (int)segment->nsects)
		{
			if (!ft_strcmp(section[j].sectname, SECT_TEXT))
				print_hex(ptr, &section[j], name, lib);
		}
	}
	segment = (void *)segment + segment->cmdsize;
}

static void			treatment_data(struct segment_command *segment,
							char *ptr, char *name, int lib)
{
	t_section			*section;
	int					j;

	section = (struct section*)((void*)segment + sizeof(*segment));
	j = -1;
	if (segment->cmd == LC_SEGMENT)
	{
		while (++j < (int)segment->nsects)
		{
			if (!ft_strcmp(section[j].sectname, SECT_DATA))
				print_hex_data(ptr, &section[j], name, lib);
		}
	}
	segment = (void *)segment + segment->cmdsize;
}

void				handle(char *ptr, char *name, int lib)
{
	int							i;
	struct mach_header			*header;
	struct load_command			*lc;
	struct segment_command		*segment;

	i = 0;
	header = (struct mach_header *)ptr;
	lc = (void *)ptr + sizeof(struct mach_header);
	while (i++ < (int)header->ncmds)
	{
		segment = (struct segment_command*)lc;
		treatment(segment, ptr, name, lib);
		lc = (void *)lc + lc->cmdsize;
	}
	if ((get_flags(0) >> (ft_strchr(FLAGS, 'd') - FLAGS)) & 1)
	{
		i = 0;
		lc = (void *)ptr + sizeof(struct mach_header);
		while (i++ < (int)header->ncmds)
		{
			segment = (struct segment_command*)lc;
			treatment_data(segment, ptr, name, lib);
			lc = (void *)lc + lc->cmdsize;
		}
	}
}
