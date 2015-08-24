/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 16:59:30 by kperreau          #+#    #+#             */
/*   Updated: 2015/08/22 18:51:19 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	ft_merge(t_merge32 *merge, int start1, int end1, int end2)
{
	int *index2;
	int start2;
	int c1;
	int c2;
	int i;

	start2 = end1 + 1;
	c1 = start1;
	c2 = start2;
	index2 = ft_index(merge->index, start1, end1);
	i = start1 - 1;
	while (++i <= end2)
	{
		if (c1 == start2)
			break ;
		else if (c2 == end2 + 1)
			merge->index[i] = index2[c1++ - start1];
		else if (!ft_sort_alpha(merge->s + \
			merge->array[index2[c1 - start1]].n_un.n_strx, \
			merge->s + merge->array[merge->index[c2]].n_un.n_strx))
			merge->index[i] = index2[c1++ - start1];
		else
			merge->index[i] = merge->index[c2++];
	}
	free(index2);
}

void		ft_merge_sort_32(t_merge32 *merge, int start, int end)
{
	int		mid;

	if (start != end)
	{
		mid = (end + start) / 2;
		ft_merge_sort_32(merge, start, mid);
		ft_merge_sort_32(merge, mid + 1, end);
		ft_merge(merge, start, mid, end);
	}
}
