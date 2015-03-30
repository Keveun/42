/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:12:11 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/30 20:40:42 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <curses.h>
# include <term.h>

typedef struct termios	t_termios;

typedef struct	s_infos
{
	t_termios	term;
}				t_infos;

void			ft_select(int argc, char **argv, t_infos *infos);

#endif
