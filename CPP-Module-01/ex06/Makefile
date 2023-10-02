# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 16:56:01 by iengels           #+#    #+#              #
#    Updated: 2023/10/02 22:30:05 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Harl.cpp	\
		main.cpp

NAME = harlfilter

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
