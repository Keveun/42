# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/01/12 11:27:01 by Kevin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = libft

# Files vars

MAIN = main.c

CFILES = ft_parse.c ft_printf.c ft_options.c ft_type_s.c ft_types_x.c \
			ft_dec_convert.c ft_putnbrul.c ft_len.c ft_type_d.c \
			ft_type_u.c ft_type_o.c ft_type_p.c ft_type_c.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.c=.o)

HFILES = printf.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

#ERRORFLAGS = -Wall -Werror -Wextra -W -O3
ERRORFLAGS =

INCLUDEFLAGS = -I $(INCLUDESDIR) -I $(LIBDIR)/includes/

LIBFLAGS = -L $(LIBDIR)/ -lft

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = gcc

# Git vars

TOGIT =	$(SRC) \
		$(HEADERS) \
		$(MAIN) \
		Makefile \
		auteur \
		$(LIBDIR)

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LIBDIR)/
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
#			@$(CC) $(FLAGS) $(MAIN) libprintf.a $(LIBFLAGS) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@make -C $(LIBDIR)/ clean

fclean: clean
			@rm -f $(NAME)
			@make -C $(LIBDIR)/ fclean

relib:
		@make -C $(LIBDIR)/ re

test: $(OBJ)
	@$(CC) $(FLAGS) $(MAIN) libftprintf.a $(LIBFLAGS) -o ft_printf

%.o: %.c
			@$(CC) -o $@ -c $< $(FLAGS)

git:
		git add $(TOGIT)
		git commit -m 'auto update'
		git push
