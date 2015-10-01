# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/09/21 17:11:30 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: ft_nm ft_otool

ft_nm:
	@make -C nm/

ft_otool:
	@make -C otool/

re: fclean all

clean:
	@make -C nm/ clean
	@make -C otool/ clean

fclean:
	@make -C nm/ fclean
	@make -C otool/ fclean
