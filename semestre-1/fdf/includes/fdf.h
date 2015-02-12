/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:05:27 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/30 22:17:29 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# define WIDTH 1600
# define HEIGHT 1200
# define NAME "fdf"

typedef struct		s_point
{
	int		x;
	int		y;
	int		z;
	int		len;
	int		zoom;
}					t_point;

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			sizeline;
	char		*data;
	int			bpp;
	double		zoom;
	double		zoomz;
	double		ratio;
	int			minz;
	int			maxz;
	int			color;
	t_point		max;
	t_point		**map;
	int			x;
	int			y;
	int			text;
	int			empty;
}					t_mlx;

typedef struct		s_p
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}					t_p;

typedef struct		s_dpoint
{
	double		dx;
	double		dy;
	double		x;
	double		y;
}					t_dpoint;

/*
**BMP
*/
typedef struct		s_hbmp
{
	uint32_t	size;
	uint16_t	r1;
	uint16_t	r2;
	uint32_t	offset;
}					t_hbmp;

typedef struct		s_hwbm
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
}					t_hwbm;

void				ft_tofile(char *img);
void				ft_error(char *s);

/*
**PARSE FILE
*/
t_point				**ft_read_file(char *filename);

void				ft_draw(t_p *p, t_mlx *mx, int z1, int z2);
void				ft_loop(t_mlx *mx);
void				ft_set_colors(t_mlx *mx, int x, int y, int color);
int					ft_gap(int x, int y);
double				ft_ratio(int gap);
void				ft_fill_img(t_mlx *mx, int color);

/*
**INIT MLX
*/
void				ft_init_mlx(t_mlx *mx);

/*
**EVENT HOOK
*/
int					expose_hook(t_mlx *mx);
int					key_hook(int keycode, t_mlx *mx);
#endif
