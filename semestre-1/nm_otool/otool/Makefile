# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/09/22 22:46:57 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_otool

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = ../nm/libft

# Files vars

MAIN = src/otool_main.c

CFILES = fat.c ft_error.c handle_64.c print_data.c flags.c handle.c lib.c \
		print.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.c=.o)

HFILES = ft_otool.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O2 -march=native

INCLUDEFLAGS = -I $(INCLUDESDIR)/ -I $(LIBDIR)/includes/ -I $(LIBDIR)/printf/includes/

LIBFLAGS = -L $(LIBDIR)/ -lft

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = gcc

# Git vars

TOGIT =	$(SRC) \
		$(HEADERS) \
		$(MAIN) \
		Makefile \
		auteur \
		$(LIBDIR) \

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			@make -j -C $(LIBDIR)/
			@$(CC) $(FLAGS) $(OBJ) $(MAIN) $(LIBFLAGS) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@make -C $(LIBDIR)/ clean

fclean: clean
			@rm -f $(NAME)
			@make -j -C $(LIBDIR)/ fclean

relib:
		@make -j -C $(LIBDIR)/ re

%.o: %.c
			@$(CC) -o $@ -c $< $(FLAGS)

git:
		git add $(TOGIT)
		git commit -m 'auto update'
		git push
