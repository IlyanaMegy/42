# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 18:31:03 by ilymegy           #+#    #+#              #
#    Updated: 2024/03/28 18:31:05 by ilymegy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fragtrap
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC			=	inc/

SRC_FILES	=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all : $(NAME)

$(NAME):$(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC) -o $@ -c $<

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm $(NAME); \
	fi;

re: fclean all

.PHONY: all clean fclean re
