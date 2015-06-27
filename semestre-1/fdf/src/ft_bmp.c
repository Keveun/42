/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 18:40:45 by kperreau          #+#    #+#             */
/*   Updated: 2014/12/29 19:53:22 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_ntobipmap(int fd, int width, int height)
{
	t_hbmp	head;
	t_hwbm	whead;

	write(fd, "BM", 2);
	head.size = 54 + 24 * height * (width % 2 ? (width + 1) : width);
	head.r1 = 0;
	head.r2 = 0;
	head.offset = 54;
	write(fd, &head, sizeof(t_hbmp));
	whead.hsize = 40;
	whead.width = width;
	whead.height = height;
	whead.nc = 1;
	whead.bpp = 24;
	whead.comp = 0;
	whead.img_size = head.size - 54;
	whead.hppm = 2835;
	whead.vppm = 2835;
	whead.nbcolor = 0;
	whead.inbcolor = 0;
	write(fd, &whead, sizeof(t_hwbm));
}

static void		ft_tobipmap(int fd, char *img, int width, int height)
{
	int		j;
	int		i;

	ft_ntobipmap(fd, width, height);
	width *= 4;
	i = height * (width);
	while (i >= 0)
	{
		j = 0;
		while (j < width)
		{
			write(fd, &(img[i + j]), 3);
			j += 4;
		}
		i -= width;
	}
}

void			ft_tofile(char *img)
{
	int		fd;

	if ((fd = open("fdf.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		exit(0);
	ft_tobipmap(fd, img, WIDTH, HEIGHT);
	close(fd);
}
