/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 18:09:42 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/15 15:18:25 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE2_H
# define COLLE2_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;
int				ft_strlen(char *str);
t_list			*ft_create_elem(void *data);
void			ft_list_push_back(t_list **begin_list, void *data);
int				loop_square(int x, int y, char *gen_square, char *value);
void			ft_putstr(char *str);
int				size(char *buf, int *result);
int				ft_strcmp(char *s1, char *s2);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
#endif
