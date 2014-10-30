/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 16:39:30 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/08 17:09:52 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H
typedef struct	s_stock_par
{
	int size_param;
	char *str;
	char *copy;
	char **tab;
}				t_stock_par;
#endif
