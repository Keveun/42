/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:40:01 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/12 18:50:04 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# define NAME "ft_minishell1"

/*
**Define pour tableau de pointeur sur fonction
*/
# define NBRCMD (5 + 1)
# define CMD_1 "exit"
# define CMD_2 "env"
# define CMD_3 "setenv"
# define CMD_4 "unsetenv"
# define CMD_5 "cd"

/*
**Tableau de pointeur sur fonction
*/
typedef void	(*t_pfunc[NBRCMD])(char **cmd, t_list **lenv);

int				ft_shell(t_list **lenv);
char			**ft_splitword(const char *s);
char			*ft_findpath(t_list *lenv);
void			ft_printerror(char *s1, char *s2, int type);
char			*ft_getpath(char **paths, char **cmd);
t_list			*ft_find_env(t_list *lenv, char *s);
t_list			*ft_find_envpop(t_list *lenv, char *s);
char			*ft_find_var(t_list *lenv, char *tofind, int type);
int				ft_parse_stdin(char *line, t_list **lenv);
int				ft_ishere(char c, char *s);
char			*ft_str_tolower(char *s);

/*
**Fonctions commandes
*/
void			ft_cmd_bin(char **cmd, t_list **lenv);
void			ft_cmd_exit(char **cmd, t_list **lenv);
void			ft_cmd_env(char **cmd, t_list **lenv);
void			ft_cmd_setenv(char **cmd, t_list **lenv);
void			ft_cmd_unsetenv(char **cmd, t_list **lenv);
void			ft_cmd_cd(char **cmd, t_list **lenv);

#endif
