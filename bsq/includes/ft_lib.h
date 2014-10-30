/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 18:09:42 by kperreau          #+#    #+#             */
/*   Updated: 2014/10/09 04:50:22 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUF_SIZE	512
# define BUF_MAX	262144
typedef struct	s_data
{
	int total_lines;
	int len;
	int offset;
	int hlen;
	int bsq[3];
	int check[2];
	char str[3];
	int *map;
}				t_data;
int				ft_read_stdin(char *filename);
int				ft_read_file(char *filename, t_data *data);
int				ft_strlen_n(char *str, int from);
int				ft_check_first_line(char *str, t_data *data);
void			ft_show_map(char *filename, t_data *data, int argc);
char			*ft_realloc_buffer(char *buf, int *d_buf);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_header(char *filename, t_data *data);
#endif