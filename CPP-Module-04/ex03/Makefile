# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:43:38 by iengels           #+#    #+#              #
#    Updated: 2023/10/29 16:03:19 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	AMateria.cpp		\
		Character.cpp		\
		Cure.cpp			\
		Ice.cpp				\
		main.cpp			\
		MateriaSource.cpp


OBJ = $(SRC:.cpp=.o)

NAME = interfaces

CXX = c++

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
