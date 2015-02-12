/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:44:18 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:23:51 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 65536

/*
**LIST
*/
typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

/*
**PARTIE 1
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long			ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**PARTIE 2
*/
char			*ft_strnew(size_t size);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(long n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(long n);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(long n, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strclr(char *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));

/*
**PERSONNAL FUNCTIONS
*/
void			ft_swap_ptr(char **s1, char **s2);
t_list			*ft_create_list(char *str);
t_list			*ft_add_list(t_list *list, char *str);
void			ft_del_list(t_list **list);
void			ft_pop_elem(t_list *elem, t_list *prev);
int				ft_count_elem(t_list *list);
void			ft_show_list(t_list *list, int newline);
int				ft_nbrlen(long n);
void			ft_strrev(char *str);
void			ft_swap(int *a, int *b);
int				ft_binlen(int n);
t_list			*ft_tab_to_list(char **tab);
char			**ft_list_to_tab(t_list *list);
int				ft_iswhitespace(char c);
void			ft_freetab(char **tab);

/*
**GET NEXT LINE
*/
typedef struct	s_lst
{
	struct s_lst	*next;
	char			buff[BUFF_SIZE + 1];
	const char		*buf;
	int				ret;
	size_t			n;
}				t_lst;

typedef struct	s_info
{
	t_lst	*head;
	t_lst	*tail;
	int		len;
}				t_info;

int				get_next_line(int const fd, char **line);
void			ft_init_gnl(t_info **info);
int				ft_reset_gnl(t_info **info);
#endif
