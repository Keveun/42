/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:40:01 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/25 18:21:51 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <curses.h>

/*
**PERSONNAL VARS
*/
# define NAME "wolf3d"
# define WIDTH 1000
# define HEIGHT 600
# define START 1
# define TEXTURE 3
# define MINIMAP 5

typedef enum	e_type
{
	WALL,
	GROUND,
	CEILING,
	SKY
}				t_type;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_dcoord
{
	double		x;
	double		y;
}				t_dcoord;

typedef struct	s_vars
{
	uint8_t		color[3];
	t_dcoord	pos;
	t_dcoord	dir;
	t_dcoord	plane;
	t_dcoord	raypos;
	t_dcoord	raydir;
	t_dcoord	distwall;
	t_dcoord	sizewall;
	t_dcoord	wall;
	t_dcoord	adir;
	t_dcoord	floor;
	t_dcoord	camera;
	t_coord		map;
	t_coord		step;
	t_coord		tex;
	double		correctwalldist;
	int			lineheight;
	int			side;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	double		rotspeedc;
	double		rotspeeds;
}				t_vars;

typedef struct	s_img
{
	int			height;
	int			width;
	char		**data;
}				t_img;

typedef struct	s_map
{
	int			height;
	int			width;
	char		**data;
	t_img		img[10];
	t_img		sky;
	t_img		floor;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			endian;
	int			height;
	int			width;
	int			top;
	int			bottom;
	int			left;
	int			right;
	int			screen;
	int			b;
	t_map		map;
	t_vars		v;
	char		*tdata[HEIGHT];
	int			mode;
}				t_mlx;

/*
**BMP
*/
typedef struct	s_hbmp
{
	uint32_t	size;
	uint16_t	r1;
	uint16_t	r2;
	uint32_t	offset;
}				t_hbmp;

typedef struct	s_hwbm
{
	uint32_t	hsize;
	int32_t		width;
	int32_t		height;
	uint16_t	nc;
	uint16_t	bpp;
	uint32_t	comp;
	uint32_t	img_size;
	uint32_t	hppm;
	uint32_t	vppm;
	uint32_t	nbcolor;
	uint32_t	inbcolor;
}				t_hwbm;

void			ft_tofile(char *img);

/*
**INIT [MLX|MAP|VARS]
*/
int				ft_init_mlx(t_mlx *mx);
int				ft_init_map(t_map *map, char *filename);
int				ft_init_vars(t_vars *v, t_map *map);

/*
**FUNCTIONS
*/
void			ft_loop(t_mlx *mx);
int				ft_read_map(char *filename, t_map *map);
void			ft_display(t_mlx *mx, t_map *map, t_vars *v);
void			ft_put_pixel(t_vars *v, char *data, int num, t_type type);
void			ft_set_color(t_vars *v);
void			ft_set_sky(t_mlx *mx, t_img *sky, int x, int y);
void			ft_set_floor(t_mlx *mx, t_img *floor, int x, int y);
void			ft_draw(t_mlx *mx, int x);

/*
**WOLF3D SHELL
*/
int				ft_wolf_shell(t_mlx *mx);

/*
**RAYCASTING
*/
void			ft_raystart(t_vars *v, int x, int width);
void			ft_next_moove(t_vars *v, t_map *map);
void			ft_dist(t_mlx *mx, t_vars *v);
void			ft_floor_casting(t_vars *v);

/*
**TEXTURES
*/
void			ft_texture_x(t_map *map, t_vars *vars);
void			ft_apply_texture(t_map *map, t_vars *vars, int height, int y);
int				ft_trait_texture(int fd, t_img *img);

/*
**MINIMAP
*/
void			ft_fill_wall(int x, int y, t_mlx *mx, int type);
void			ft_minimap(t_mlx *mx, t_map *map, t_vars *vars);

/*
**EVENT HOOK
*/
int				expose_hook(t_mlx *mx);
int				key_hook(int keycode, t_mlx *mx);
int				key_press_hook(int keycode, t_mlx *mx);
int				key_release_hook(int keycode, t_mlx *mx);
int				key_loop_hook(t_mlx *mx);

/*
**MOOVE
*/
void			ft_top(t_vars *vars, t_map *map);
void			ft_bottom(t_vars *vars, t_map *map);
void			ft_left(t_vars *vars);
void			ft_right(t_vars *vars);

#endif
