# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2014/12/29 23:06:33 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = libft

# Files vars

MAIN = main.c

CFILES = ft_color.c ft_line.c ft_parse.c ft_calcul.c ft_events.c ft_init_mlx.c \
		ft_bmp.c ft_grad.c ft_error.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.c=.o)

HFILES = fdf.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O3

MLX = -L/usr/X11/lib -lmlx -lXext -lx11

INCLUDEFLAGS = -I $(INCLUDESDIR) -I $(LIBDIR)/includes/

LIBFLAGS = -L $(LIBDIR) -lft

FLAGS = $(ERRORFLAGS) $(LIBFLAGS) $(INCLUDEFLAGS) $(MLX)

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
			@$(CC) $(FLAGS) $(MAIN) $(OBJ) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@rm -f $(TMP)
			@make -C $(LIBDIR)/ clean

fclean: clean
			@rm -f $(NAME)
			@make -C $(LIBDIR)/ fclean

relib:
		@make -C $(LIBDIR)/ re

%.o: %.c
			@$(CC) -o $@ -c $< $(FLAGS)

git:
		git add $(TOGIT)
		git commit -m 'auto update'
		git push
