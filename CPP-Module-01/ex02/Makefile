# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 21:34:24 by iengels           #+#    #+#              #
#    Updated: 2023/09/20 21:34:31 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = brainz

CC = c++

CFLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
