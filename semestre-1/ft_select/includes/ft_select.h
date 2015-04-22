/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:12:11 by kperreau          #+#    #+#             */
/*   Updated: 2015/04/22 14:47:01 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

# define K_ARROW1 27
# define K_ARROW2 91
# define K_TOP 4283163
# define K_BOTTOM 4348699
# define K_LEFT 4479771
# define K_RIGHT 4414235
# define K_EXIT 27
# define K_END 4610843
# define K_HOME 4741915
# define K_DEL 2117294875
# define K_BACKSPACE 127
# define K_SPACE 32
# define K_RETURN 10
# define K_RESET 114

# define COLOR_REV "\033[7;7m"

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_args
{
	char		*str;
	int			len;
	int			visible;
	int			selected;
	int			cursor;
	t_coord		c;
	int			col;
}				t_args;

typedef struct	s_infos
{
	t_termios	term;
	t_args		*reset;
	t_args		*args;
	t_winsize	size;
	t_coord		cursor;
	char		*cl;
	char		*us;
	char		*ue;
	char		*rv;
	char		*mr;
	char		*me;
	char		*cm;
	int			nbr_args;
	int			nbr_rargs;
	int			nbr_selected;
	int			nbr_visible;
	int			lastid;
	int			column;
	int			pos_col;
	int			nbr_print;
	int			start;
}				t_infos;

void			ft_select(int argc, char **argv, t_infos *infos);
t_args			*ft_args(int argc, char **argv);
t_args			*ft_n_args(int argc, t_infos *infos, int id);
int				ft_my_outc(int c);
void			ft_resize(int ptr);
t_infos			*ft_singleton(void);
int				ft_display(t_infos *infos);
void			ft_moove(t_infos *infos, int key);
int				ft_find_longest(t_args *args, int end);
void			ft_out(t_infos *infos);
int				ft_delete(t_infos *infos);

#endif
