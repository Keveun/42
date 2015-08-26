/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 10:21:30 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/26 17:09:39 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H

# define FT_NM_OTOOL_H

# include "libft.h"
# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include </usr/include/ar.h>

# define FLAGS "gpjr"
# define FLAG_G	1
# define FLAG_P	2
# define FLAG_J 4
# define FLAG_R 8

typedef struct	s_merge
{
	struct nlist_64	*array;
	char			*s;
	int				*index;
}				t_merge;

typedef struct	s_merge32
{
	struct nlist	*array;
	char			*s;
	int				*index;
}				t_merge32;

typedef struct	s_lib
{
	char			*start;
	unsigned int	st_len;
	unsigned int	arr_len;
	char			*str;
}				t_lib;

typedef struct mach_header_64	t_mach_header_64;
typedef struct mach_header		t_mach_header;
typedef struct fat_header		t_fat_header;
typedef struct nlist_64			t_nlist_64;
typedef struct nlist			t_nlist;

/*
** Main functions
*/
int				ft_nm(int fd, char *file, int n);
void			ft_handle64(char *ptr, struct mach_header_64 *header);
void			ft_handle(char *ptr, struct mach_header *header);
int				ft_options(int argc, char **argv, int *args);

/*
** Tools
*/
void			ft_merge_sort(t_merge *merge, int start, int end);
void			ft_merge_sort_32(t_merge32 *merge, int start, int end);
int				*ft_index(int *index, int start, int end);
int				ft_sort_alpha(char *s1, char*s2);
int				ft_test(void);
unsigned int	ft_rev_int(unsigned int num);

/*
** Error
*/
int				ft_error_options(char msg);
int				ft_error_file(char *msg);

/*
** Libs
*/
void			ft_lib(char *ptr, char *file, int size);

/*
** Fat
*/
void			ft_fat_handle(char *ptr, t_fat_header *header,\
					char *file);

/*
** Display 64 bits
*/
void			ft_output(struct symtab_command *sym, \
					char **sec_str, char *ptr);
void			ft_display_type(struct nlist_64 *array, char **sec_str);
void			ft_display_sec(struct nlist_64 *array, char **sec_str);

/*
** Display 32 bits
*/
void			ft_output_32(struct symtab_command *sym, \
					char **sec_str, char *ptr);
void			ft_display_type_32(struct nlist *array, char **sec_str);
void			ft_display_sec_32(struct nlist *array, char **sec_str);
#endif
