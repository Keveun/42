# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 23:57:15 by kperreau          #+#    #+#              #
#    Updated: 2014/09/09 00:43:50 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_putchar.c \
	srcs/ft_swap.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_strcmp.c

OFILES = ft_putchar.o \
	ft_swap.o \
	ft_putstr.o \
	ft_strlen.o \
	ft_strcmp.o

HEADERS = includes/

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRC)  -I $(HEADERS) && ar rc $(NAME) $(OFILES) && ranlib $(NAME)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
