/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 22:53:22 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 23:12:53 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree *btree_create_node(void *item)
{
	t_btree		*btree;

	btree = malloc(sizeof(t_btree));
	btree->item = item;
	btree->left = NULL;
	btree->right = NULL;
	return (btree);
}
