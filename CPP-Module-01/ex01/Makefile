# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 19:06:03 by iengels           #+#    #+#              #
#    Updated: 2023/09/30 02:02:55 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Zombie.cpp		\
		zombieHorde.cpp	\
		main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = morebrainz

CC = c++

CPPFLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
