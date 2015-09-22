/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 17:07:21 by kperreau          #+#    #+#             */
/*   Updated: 2015/09/22 22:35:14 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void				print_head_64(struct section_64 *section, char *name,
		int print)
{
	if (print == 0)
		ft_printf("%s:\n", name);
	ft_printf("(%s,%s) section\n", section->segname, section->sectname);
	if (print != -1 && section->size != 0)
		ft_printf("%.16llx ", section->addr);
	else if (print == -1 && section->size != 0)
		ft_printf("%.16llx\t", section->addr);
}

void				print_hex_64(char *ptr, struct section_64 *section,
		char *name, int print)
{
	int						k;
	char					c;
	struct mach_header		*h;

	h = (struct mach_header*)ptr;
	k = 0;
	print_head_64(section, name, print);
	while (k < (int)section->size)
	{
		c = *(ptr + (int)(section->offset) + k++);
		ft_printf("%.2hhx", c);
		if (print != -1 && k % 16 == 0 && k != (int)section->size)
			ft_printf(" \n%.16llx ", section->addr + k);
		else if (print == -1 && k % 16 == 0 && k != (int)section->size)
			ft_printf(" \n%.16llx\t", section->addr + k);
		else
			ft_putchar(' ');
	}
	if (section->size != 0)
		ft_putchar('\n');
}

void				print_head(struct section *section, char *name, int print)
{
	if (print == 0)
		ft_printf("%s:\n", name);
	ft_printf("(%s,%s) section\n", section->segname, section->sectname);
	if (print != -1 && section->size != 0)
		ft_printf("%.8x ", section->addr);
	else if (print == -1 && section->size != 0)
		ft_printf("%.8x\t", section->addr);
}

void				print_hex(char *ptr, struct section *section,
		char *name, int print)
{
	int		k;
	char	c;

	k = 0;
	print_head(section, name, print);
	while (k < (int)section->size)
	{
		c = *(ptr + (int)(section->offset) + k++);
		ft_printf("%.2hhx", c);
		if (print != -1 && k % 16 == 0 && k != (int)section->size)
			ft_printf(" \n%.8x ", section->addr + k);
		else if (print == -1 && k % 16 == 0 && k != (int)section->size)
			ft_printf(" \n%.8x\t", section->addr + k);
		else
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void				fat_header(T_FAT_HEADER *header, T_FAT_ARCH *arch)
{
	int i;

	i = -1;
	ft_printf("Fat headers\nfat_magic 0x%x\nnfat_arch %d\n",
			ft_rev_int(header->magic), ft_rev_int(header->nfat_arch));
	while (++i < (int)ft_rev_int(header->nfat_arch))
	{
		ft_printf("architecture %d\n    ", i);
		ft_printf("cputype %d\n    ", ft_rev_int(arch->cputype));
		ft_printf("cpusubtype %d\n    ", ft_rev_int(arch->cpusubtype) & \
				~CPU_SUBTYPE_MASK);
		ft_printf("capabilities 0x%x\n    ", ft_rev_int(\
				ft_rev_int(arch->cpusubtype) & CPU_SUBTYPE_LIB64));
		ft_printf("offset %d\n    ", ft_rev_int(arch->offset));
		ft_printf("size %d\n    ", ft_rev_int(arch->size));
		ft_printf("align 2^%d (%d)\n", ft_rev_int(arch->align),
				1 << ft_rev_int(arch->align));
		arch = (void*)arch + sizeof(*arch);
	}
}
