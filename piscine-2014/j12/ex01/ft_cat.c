/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 15:03:26 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/11 21:54:45 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE	28

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int		ft_openfile(int argc, char **filename)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		i;

	i = 1;
	while (i < argc)
	{
		fd = open(filename[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("cat: ");
			ft_putstr(filename[i]);
			ft_putstr(": No such file or directory\n");
			return (1);
		}
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		close(fd);
		i++;
	}
	return (0);
}

int		ft_input(void)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	while ((ret = read(0, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_input();
	else if (argc > 1)
		ft_openfile(argc, argv);
	return (0);
}
