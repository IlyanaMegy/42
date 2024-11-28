# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 11:43:28 by ilymegy           #+#    #+#              #
#    Updated: 2024/03/11 11:43:31 by ilymegy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	brain
CXX			=	c++
CXXFLAGS	=	-Wextra -Werror -Wall -std=c++98

SRC			=	main.cpp
OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all	:	$(NAME)

$(NAME):$(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -rf $(NAME); \
	fi;

re: fclean all

.PHONY: all clean fclean re