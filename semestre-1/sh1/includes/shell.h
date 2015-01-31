/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:40:01 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/19 16:46:04 by kperreau         ###   ########.fr       */
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


int				ft_shell(char **env);
char			**ft_splitword(const char *s);
char			*ft_findpath(t_list *lenv);
void			ft_printerror(char *s, int type);
char			*ft_getpath(char **paths, char **cmd);
t_list			*ft_find_env(t_list *lenv, char *s);
t_list			*ft_find_envpop(t_list *lenv, char *s);

#endif
