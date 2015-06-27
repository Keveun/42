/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 20:16:08 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/21 20:16:11 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# define BUFF_SIZE 8

typedef struct	s_file
{
	struct s_file	*next;
	struct s_file	*prev;
	char			*buff;
	char			*begin;
	int				fd;
}				t_file;

int				get_next_line(int const fd, char **line);
#endif
