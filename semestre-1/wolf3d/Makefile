# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/03/02 20:40:15 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = libft

# Files vars

MAIN = main.c

CFILES = ft_color.c ft_event.c ft_init_mlx.c ft_run.c ft_moove.c ft_read_map.c \
			ft_raycast.c ft_bmp.c ft_init_map.c ft_texture.c ft_init_vars.c \
			ft_draw.c ft_minimap.c ft_run_shell.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.c=.o)

HFILES = wolf3d.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O3
# ERRORFLAGS = -O3

#INCLUDEFLAGS = -I $(INCLUDESDIR)/ -I $(LIBDIR)/includes/
INCLUDEFLAGS = -I $(INCLUDESDIR)/ -I $(LIBDIR)/includes/ -I./mlx

#MLX = -L/usr/X11/lib -lmlx -lx11 -lXext
MLX = -L./mlx -framework OpenGL -framework AppKit -lmlx

LIBFLAGS = -L $(LIBDIR)/ -lft -lcurses

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
			@make -j -C $(LIBDIR)/
			@make -j -C mlx/
			@$(CC) $(FLAGS) $(OBJ) $(MAIN) $(LIBFLAGS) $(MLX) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@make -C $(LIBDIR)/ clean
			@make -C mlx/ clean

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
