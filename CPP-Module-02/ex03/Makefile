# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 23:59:50 by iengels           #+#    #+#              #
#    Updated: 2023/10/02 22:11:22 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp	\
		Fixed.cpp	\
		Point.cpp	\
		bsp.cpp

OBJ = $(SRC:.cpp=.o)

NAME = bsp

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
