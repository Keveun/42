# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/04 15:19:03 by kperreau          #+#    #+#              #
#    Updated: 2015/03/24 17:00:22 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

# Dir vars

INCLUDESDIR = includes

# Files vars

SFILES = ft_isdigit.s ft_isascii.s ft_isalpha.s ft_isprint.s ft_isalnum.s \
		ft_toupper.s ft_tolower.s ft_bzero.s ft_strcat.s ft_strlen.s ft_puts.s \
		ft_memset.s ft_memcpy.s ft_strdup.s ft_cat.s ft_isspace.s ft_swap.s \
		ft_strcpy.s ft_putnbr.s ft_strcmp.s
		
OBJ = $(SFILES:.s=.o)

FLAGS = -Wall -Werror -Wextra

# COMPILATION

all: $(NAME)

$(NAME): $(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@rm -f main.o

fclean: clean
			@rm -f $(NAME)
			@rm -rf test

%.o: %.s
			nasm -f macho64 $< -o $@

git:
	git add $(SFILES)
	git add main.c
	git add Makefile
	git commit -m "autoupdate"
	git push

test: $(NAME) main.o
	@gcc $(FLAGS) -I. main.o libfts.a -o test

main.o: main.c
	@gcc $(FLAGS) -c -I. main.c
