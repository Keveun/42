# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/15 17:55:58 by kperreau          #+#    #+#              #
#    Updated: 2014/10/11 19:48:49 by Kevin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/ft_strlen_n.c \
	srcs/ft_strncpy.c \
	srcs/main.c \
	srcs/input.c \
	srcs/check_first_line.c \
	srcs/trait_file.c \
	srcs/show_map.c

OFILES = ft_strlen_n.o \
	ft_strncpy.o \
	main.o \
	input.o \
	check_first_line.o \
	trait_file.o \
	show_map.o

HEADERS = includes/

FLAGS = -Wall -Wextra -Werror -s -O3
# FLAGS = -s -O3

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) -I $(HEADERS)
	@gcc $(FLAGS) $(OFILES) -o $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all