/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 21:27:12 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/10 22:40:03 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;
t_list			*ft_create_elem(void *data);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
#endif
