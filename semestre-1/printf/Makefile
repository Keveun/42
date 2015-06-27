# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/01/15 23:13:03 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = libft

# Files vars

MAIN = main.c

CFILES = ft_parse.c ft_printf.c ft_options.c ft_type_s.c ft_type_x.c \
			ft_dec_convert.c ft_putnbrul.c ft_len.c ft_type_d.c \
			ft_type_u.c ft_type_o.c ft_type_p.c ft_type_c.c ft_utf8.c \
			ft_type_b.c ft_type_g.c ft_leet.c

LIBFILES = ft_atoi.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c \
			ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strstr.c ft_isalnum.c \
			ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c \
			ft_strsub.c ft_isalpha.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c \
			ft_striteri.c ft_strncpy.c ft_strtrim.c ft_isascii.c ft_memchr.c \
			ft_putendl.c ft_strclr.c ft_strjoin.c ft_strnequ.c ft_swap_ptr.c \
			ft_isdigit.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c ft_strlcat.c \
			ft_strnew.c ft_tolower.c ft_isprint.c ft_memcpy.c ft_putnbr.c \
			ft_strcpy.c ft_strlen.c ft_strnstr.c ft_toupper.c ft_itoa.c \
			ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strrchr.c \
			get_next_line.c ft_funcs.c ft_strsplit.c ft_bzero.c ft_memset.c \
			ft_create_list.c ft_add_list.c ft_del_list.c ft_nbrlen.c \
			ft_swap.c ft_strrev.c ft_binlen.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES)) $(patsubst %, $(LIBDIR)/%, $(LIBFILES))

OBJ = $(SRC:.c=.o)

HFILES = printf.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O3

INCLUDEFLAGS = -I $(INCLUDESDIR) -I $(LIBDIR)/includes/

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
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)

fclean: clean
			@rm -f $(NAME)

test: $(OBJ)
	@$(CC) $(FLAGS) $(MAIN) libftprintf.a -o ft_printf

%.o: %.c
			@$(CC) -o $@ -c $< $(FLAGS)

git:
		git add $(TOGIT)
		git commit -m 'auto update'
		git push
