/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 10:45:47 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/24 18:52:17 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_handle(char *ptr, t_mach_header *header)
{
	struct load_command			*lc;
	int							i;
	int							j;
	int							k;
	char						*sec_str[255];

	lc = (void*)ptr + sizeof(*header);
	i = -1;
	j = -1;
	while (++i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			k = -1;
			while (++k < ((struct segment_command*)lc)->nsects)
				sec_str[++j] = ((struct section*)((void*)lc + \
					sizeof(struct segment_command)))[k].sectname;
		}
		if (lc->cmd == LC_SYMTAB)
		{
			ft_output_32((struct symtab_command*)lc, sec_str, ptr);
			break ;
		}
		lc = (void*)lc + lc->cmdsize;
	}
}

void	ft_handle64(char *ptr, t_mach_header_64 *header)
{
	struct load_command			*lc;
	int							i;
	int							j;
	int							k;
	char						*sec_str[255];

	lc = (void*)ptr + sizeof(*header);
	i = -1;
	j = -1;
	while (++i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			k = -1;
			while (++k < ((struct segment_command_64*)lc)->nsects)
				sec_str[++j] = ((struct section_64*)((void*)lc + \
					sizeof(struct segment_command_64)))[k].sectname;
		}
		if (lc->cmd == LC_SYMTAB)
		{
			ft_output((struct symtab_command*)lc, sec_str, ptr);
			break ;
		}
		lc = (void*)lc + lc->cmdsize;
	}
}

int		ft_nm(int fd, char *file, int n)
{
	char			*ptr;
	struct stat		buf;
	unsigned int	magic_number;

	if (fstat(fd, &buf) < 0)
		return (EXIT_FAILURE);
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))\
		== MAP_FAILED)
		return (EXIT_FAILURE);
	magic_number = *(unsigned int*)ptr;
	if ((magic_number == MH_MAGIC_64 || magic_number == FAT_CIGAM ||
		magic_number == FAT_MAGIC || magic_number == MH_MAGIC ||
		!ft_strncmp(ptr, file, buf.st_size)) && n > 0)
		ft_printf("\n%s:\n", file);
	if (magic_number == MH_MAGIC_64)
		ft_handle64(ptr, (struct mach_header_64*)ptr);
	if (magic_number == MH_MAGIC)
		ft_handle(ptr, (struct mach_header*)ptr);
	if (magic_number == FAT_CIGAM || magic_number == FAT_MAGIC)
		ft_fat_handle(ptr, (struct fat_header*)ptr, file, buf.st_size);
	if (!ft_strncmp(ptr, ARMAG, SARMAG))
		ft_lib(ptr, file, buf.st_size);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	return (0);
}
