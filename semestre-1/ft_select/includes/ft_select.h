/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:12:11 by kperreau          #+#    #+#             */
/*   Updated: 2015/05/21 17:47:17 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
# define K_SELALL 49
# define K_DESELALL 50
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"
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
	int			page[32000];
	int			id_page;
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
	int			prev_nbr_args;
	int			lastid;
	int			column;
	int			pos_col;
	int			nbr_print;
	int			start;
	int			end;
	int			fd;
	int			redisp;
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
void			ft_init_disp(t_infos *infos);
void			ft_resize_error(t_infos *infos);
t_args			*ft_reset_args(t_infos *infos);
void			ft_reset(t_infos *infos);
int				ft_reset_term(t_termios *term, t_infos *infos);
void			ft_sig_int(int sig);
void			ft_sig_stop(int sig);
void			ft_sig_cont(int sig);
int				ft_init_term(t_termios *term, t_infos *infos);
void			ft_select_all(t_infos *infos, int code);

#endif
