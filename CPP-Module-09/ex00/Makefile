# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 21:52:21 by iengels           #+#    #+#              #
#    Updated: 2023/11/16 15:35:43 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp	\
		BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

NAME = btc

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp BitcoinExchange.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re