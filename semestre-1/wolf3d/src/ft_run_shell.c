/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:10:26 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 18:28:09 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define ESCAPE 27
#define TOP 259
#define BOTTOM 258
#define LEFT 260
#define RIGHT 261

int				ft_init_shell(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_RED);
	init_pair(5, COLOR_GREEN, COLOR_GREEN);
	init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_YELLOW, COLOR_BLACK);
	init_pair(11, COLOR_GREEN, COLOR_BLACK);
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	return (0);
}

static void		ft_draw_column(t_mlx *mx, t_vars *v, int y, int x)
{
	if (!v->side)
		attron(COLOR_PAIR((mx->mode) ? 8 : 3));
	else
		attron(COLOR_PAIR((mx->mode) ? 9 : 4));
	if (v->pos.x > v->map.x && !v->side)
		attron(COLOR_PAIR((mx->mode) ? 11 : 5));
	else if (v->pos.y < v->map.y && v->side)
		attron(COLOR_PAIR((mx->mode) ? 10 : 6));
	mvprintw(y, x, "0");
}

static void		ft_draw_shell(t_mlx *mx, int x)
{
	int		y;

	if (mx->v.drawend < 0)
		return ;
	y = -1;
	while (++y < HEIGHT)
	{
		if (y < mx->v.drawstart)
		{
			attron(COLOR_PAIR((mx->mode) ? 3 : 2));
			mvprintw(y, x, "0");
		}
		else if (y <= mx->v.drawend)
			ft_draw_column(mx, &mx->v, y, x);
		else
		{
			attron(COLOR_PAIR((mx->mode) ? 3 : 1));
			mvprintw(y, x, "0");
		}
	}
}

static int		ft_run_shell(t_mlx *mx, t_map *map, t_vars *v)
{
	int		x;

	x = -1;
	while (++x < mx->width)
	{
		ft_raystart(v, x, mx->width);
		ft_next_moove(v, map);
		ft_dist(mx, v);
		ft_draw_shell(mx, x);
	}
	return (0);
}

int				ft_wolf_shell(t_mlx *mx)
{
	int		key;

	key = 0;
	mx->mode = 1;
	ft_init_shell();
	while (key != ESCAPE)
	{
		mx->height = getmaxy(stdscr);
		mx->width = getmaxx(stdscr);
		ft_run_shell(mx, &mx->map, &mx->v);
		wrefresh(stdscr);
		key = getch();
		if (key == TOP)
			ft_top(&mx->v, &mx->map);
		else if (key == BOTTOM)
			ft_bottom(&mx->v, &mx->map);
		else if (key == LEFT)
			ft_left(&mx->v);
		else if (key == RIGHT)
			ft_right(&mx->v);
		mx->mode = (key == 45) ? !mx->mode : mx->mode;
	}
	endwin();
	return (0);
}
