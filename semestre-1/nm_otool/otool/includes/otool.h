/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 17:05:52 by kperreau          #+#    #+#             */
/*   Updated: 2015/09/22 17:05:54 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <ar.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "libft.h"

# define FLAGS "df"
# define T_SEG_CMD_64 struct segment_command_64
# define T_SEC_64 struct section_64
# define T_FAT_HEADER struct fat_header
# define T_FAT_ARCH struct fat_arch

typedef struct			s_lib
{
	char			*start;
	unsigned int	st_len;
	unsigned int	arr_len;
	char			*str;
}						t_lib;
typedef struct			s_segflag
{
	char			*seg_name;
	char			*sect_name;
}						t_segflag;
typedef struct section	t_section;

int						ft_flags(char **av);
unsigned int			ft_rev_int(unsigned int i);
unsigned int			get_flags(unsigned int flag);
void					otool(char *ptr, char *name, int size);
void					print_hex(char *ptr, struct section *section,
								char *name, int lib);
void					print_hex_data(char *ptr, struct section *section,
								char *name, int print);
void					print_head(struct section *section, char *name,
								int print);
void					print_hex_64(char *ptr, struct section_64 *section,
								char *name, int lib);
void					print_hex_data_64(char *ptr, struct section_64 *section,
								char *name, int print);
void					print_head_64(struct section_64 *section, char *name,
								int print);
void					print_ar(struct ar_hdr *ar);
void					fat_header(T_FAT_HEADER *header, T_FAT_ARCH *arch);
void					handle(char *ptr, char *name, int lib);
void					handle_64(char *ptr, char *name, int lib);
void					handle_lib(char *ptr, char *name, int size);
void					fat(char *ptr, struct fat_header *header, char *name);
void					ft_error_object(char *s);
void					ft_error_open(char *s, char *s1);

#endif
