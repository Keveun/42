/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 23:08:21 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/24 16:43:26 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

int			ft_isdigit();
int			ft_isascii();
int			ft_isalpha();
int			ft_isprint();
int			ft_isalnum();
int			ft_toupper();
int			ft_tolower();
void		ft_bzero();
char		*ft_strcat();
size_t		ft_strlen();
void		ft_puts(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
void		ft_cat(int fd);

/*
** BONUS
*/
int			ft_isspace(char c);
void		ft_swap(long *a, long *b);
char		*ft_strcpy(char *dst, const char *src);
void		ft_putnbr(size_t n);
int			ft_strcmp(const char *s1, const char *s2);

#endif
