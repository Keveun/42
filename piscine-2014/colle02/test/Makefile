# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/14 15:25:50 by kperreau          #+#    #+#              #
#    Updated: 2014/09/15 15:20:04 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SRC = srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_strcmp.c \
	srcs/main.c \
	srcs/colle00.c \
	srcs/check.c \
	srcs/ft_create_elem.c \
	srcs/ft_list_push_back.c \
	srcs/ft_putnbr.c \
	srcs/ft_putchar.c

OFILES = ft_putchar.o \
	ft_putstr.o \
	ft_strlen.o \
	ft_strcmp.o \
	ft_putnbr.o \
	main.o \
	colle00.o \
	check.o \
	ft_create_elem.o \
	ft_list_push_back.o

HEADERS = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(FLAGS) -c $(SRC) -I $(HEADERS)
	cc $(OFILES) -o $(NAME)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
