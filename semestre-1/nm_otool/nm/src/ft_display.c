/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 22:24:21 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/26 16:55:42 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void		ft_display_sec(struct nlist_64 *array, char **sec_str)
{
	if (array->n_sect)
	{
		if (!ft_strcmp(sec_str[array->n_sect - 1], SECT_TEXT))
			(array->n_type & 1) ? ft_printf("T ") : ft_printf("t ");
		else if (!ft_strcmp(sec_str[array->n_sect - 1], SECT_BSS))
			(array->n_type & 1) ? ft_printf("B ") : ft_printf("b ");
		else if (!ft_strcmp(sec_str[array->n_sect - 1], SECT_DATA))
			(array->n_type & 1) ? ft_printf("D ") : ft_printf("d ");
		else if (!ft_strcmp(sec_str[array->n_sect - 1], SECT_COMMON))
			(array->n_type & 1) ? ft_printf("S ") : ft_printf("s ");
		else if (!ft_strcmp(sec_str[array->n_sect - 1], "__cstring"))
			(array->n_type & 1) ? ft_printf("S ") : ft_printf("s ");
		else
			(array->n_type & 1) ? ft_printf("S ") : ft_printf("s ");
	}
}

void		ft_display_type(struct nlist_64 *array, char **sec_str)
{
	if ((array->n_type & N_TYPE) == N_UNDF)
		(array->n_value) ? ft_printf("C ") : ft_printf("U ");
	else if ((array->n_type & N_TYPE) == N_SECT)
		ft_display_sec(array, sec_str);
	else if ((array->n_type & N_TYPE) == N_ABS)
		ft_printf("A ");
	else if ((array->n_type & N_TYPE) == N_INDR)
		ft_printf("I ");
}

static int	ft_check_bonus(t_nlist_64 *nlist)
{
	int		flags;

	flags = ft_options(0, NULL, NULL);
	if ((flags & FLAG_G) && !(nlist->n_type & 1))
		return (1);
	return (0);
}

static void	ft_sub_out(t_merge *merge, char **sec_str, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		if ((merge->array[merge->index[i]].n_type & N_STAB) ||
			ft_check_bonus(&merge->array[merge->index[i]]))
			continue ;
		if (((merge->array[merge->index[i]].n_type & N_TYPE) != N_UNDF ||
			merge->array[merge->index[i]].n_value) &&
			(merge->array[merge->index[i]].n_type & N_TYPE) != N_INDR &&
			!(ft_options(0, NULL, NULL) & FLAG_J))
			ft_printf("%16ll0x ", merge->array[merge->index[i]].n_value);
		else if (!(ft_options(0, NULL, NULL) & FLAG_J))
			ft_printf("%16s ", "");
		if (!(ft_options(0, NULL, NULL) & FLAG_J))
			ft_display_type(merge->array + merge->index[i], sec_str);
		if ((merge->array[merge->index[i]].n_type & N_TYPE) == N_INDR)
			ft_printf("%s (indirect for %s)\n", \
				merge->s + merge->array[merge->index[i]].n_un.n_strx, \
				merge->s + merge->array[merge->index[i]].n_value);
		else
			ft_printf("%s\n", merge->s + \
				merge->array[merge->index[i]].n_un.n_strx);
	}
}

void		ft_output(struct symtab_command *sym, char **sec_str, char *ptr)
{
	int				i;
	char			*stringtable;
	struct nlist_64	*array;
	int				*index;
	t_merge			merge;

	array = (void*)ptr + sym->symoff;
	stringtable = (void*)ptr + sym->stroff;
	if ((index = malloc(sizeof(int) * sym->nsyms)) == NULL)
		return ;
	i = -1;
	while (++i < (int)sym->nsyms)
		index[i] = i;
	merge.index = index;
	merge.array = array;
	merge.s = stringtable;
	if (!(ft_options(0, NULL, NULL) & FLAG_P))
		ft_merge_sort(&merge, 0, sym->nsyms - 1);
	ft_sub_out(&merge, sec_str, sym->nsyms);
	free(index);
}
