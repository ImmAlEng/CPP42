# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 19:06:03 by iengels           #+#    #+#              #
#    Updated: 2023/10/02 22:13:25 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Zombie.cpp		\
		newZombie.cpp	\
		randomChump.cpp	\
		main.cpp

NAME = brainz

OBJ = $(SRC:.cpp=.o)

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
