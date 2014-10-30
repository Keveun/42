/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 10:10:28 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 10:20:28 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
# include <string.h>
# define SAVE_AUSTIN_POWERS	1
typedef struct	s_perso
{
	char	*name;
	float	life;
	int		age;
	int		profession;
}				t_perso;
#endif
