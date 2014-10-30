/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 10:08:10 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/12 10:08:36 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perso.h"
int main()
{
	t_perso donnie;
	donnie.name = strdup("Donnie");
	donnie.life = 100.0;
	donnie.age = 24;
	donnie.profession = SAVE_AUSTIN_POWERS;
	(void)donnie;
	return (0);
}
