/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:40:01 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/11 20:06:10 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "stdio.h"

typedef struct	s_data
{
	int			*a;
	int			*b;
	int			na;
	int			nb;
	int			n;
	int			opti;
	int			debug;
	int			count;
}				t_data;

void			ft_push_swap(char **tab, int n);
int				ft_isnumbers(char **tab, int n);
int				ft_isdouble(int *a, int size, int value);
void			ft_calc(t_data *pile);
void			ft_rotate(int *pile, int n, int display, t_data *spile);
void			ft_rev_rotate(int *pile, int n, int display, t_data *spile);
void			ft_push_b(int *a, int *b, int pb, t_data *pile);
void			ft_push_a(int *a, int *b, int pa, t_data *pile);
void			ft_swap_a(int *a, int pa, t_data *pile);
int				ft_is_sort(int *a, int n);
int				ft_check_sa(t_data *pile);
void			ft_test(int *a, int *b, int na, int debug);

#endif
