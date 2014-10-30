/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 17:11:15 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/11 23:37:44 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE	1

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int ft_atoi(char *str)
{
	int is_negative;
	int value;

	is_negative = 0;
	value = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		is_negative = 1;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = value * 10 + *str - '0';
		str++;
	}
	if (is_negative)
		value = -value;
	return (value);
}

int		count(char *filename)
{
	int		i;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
		i++;
	close(fd);
	return (i);
}

int		ft_openfile(char *filename)
{
	int		fd;
	int		ret;
	int		i;
	int		j;
	char	buf[BUF_SIZE + 1];

	i = count(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	j = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (i - 2 <= j)
		{	
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		j++;
	}
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	
	if (argc < 2)
		return (1);
	else if (argc > 1)
		ft_openfile(argv[1], argv[]);
	return (0);
}
