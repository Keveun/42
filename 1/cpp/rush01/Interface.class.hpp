/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:39:11 by kperreau          #+#    #+#             */
/*   Updated: 2015/06/27 19:04:31 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_CLASS_HPP
# define INTERFACE_CLASS_HPP

# include <iostream>
# include <string>

class Interface
{
	public:

		Interface(void);
		~Interface(void);

		void	init_ncurse(void);
		int		getKey(void);
		void	start(void);

	private:

		int		_y;
		int		_module;
		Interface(const Interface & interface);
		Interface &operator=(const Interface & interface);
};

#endif
