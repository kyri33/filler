# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kioulian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/12 17:49:45 by kioulian          #+#    #+#              #
#    Updated: 2016/06/12 17:49:48 by kioulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c game.c move.c

SRCO = main.o game.o move.o

FLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	make -C	libft/ fclean && make -C libft/
	clang $(FLAGS) $(NAME) $(SRC) libft/libft.a
clean:
	make -C libft/ clean
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
