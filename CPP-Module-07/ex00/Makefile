# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 00:16:50 by iengels           #+#    #+#              #
#    Updated: 2023/11/13 01:52:14 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = template_functions

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp whatever.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
