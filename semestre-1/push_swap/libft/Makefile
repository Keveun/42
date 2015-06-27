# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/04 15:19:03 by kperreau          #+#    #+#              #
#    Updated: 2015/01/19 17:08:07 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Dir vars

INCLUDESDIR = includes

# Files vars

CFILES = ft_atoi.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c \
			ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strstr.c ft_isalnum.c \
			ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c \
			ft_strsub.c ft_isalpha.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c \
			ft_striteri.c ft_strncpy.c ft_strtrim.c ft_isascii.c ft_memchr.c \
			ft_putendl.c ft_strclr.c ft_strjoin.c ft_strnequ.c ft_swap_ptr.c \
			ft_isdigit.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c ft_strlcat.c \
			ft_strnew.c ft_tolower.c ft_isprint.c ft_memcpy.c ft_putnbr.c \
			ft_strcpy.c ft_strlen.c ft_strnstr.c ft_toupper.c ft_itoa.c \
			ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strrchr.c \
			get_next_line.c ft_init_gnl.c ft_strsplit.c ft_bzero.c ft_memset.c \
			ft_create_list.c ft_add_list.c ft_del_list.c ft_nbrlen.c \
			ft_swap.c ft_strrev.c ft_binlen.c ft_count_elem.c ft_pop_elem.c \
			ft_tab_to_list.c ft_list_to_tab.c ft_iswhitespace.c ft_show_list.c \
			ft_freetab.c

OBJ = $(CFILES:.c=.o)

HFILES = libft.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O3 -c

INCLUDEFLAGS = -I includes/

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = gcc

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)

fclean: clean
			@rm -f $(NAME)

%.o: %.c
			@$(CC) -c $< $(FLAGS)
