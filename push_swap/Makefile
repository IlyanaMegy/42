# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 11:53:13 by ilymegy           #+#    #+#              #
#    Updated: 2023/08/25 00:14:04 by ilymegy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pushswap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3

INC			= -I ./inc/\
			-I ./libft/
			
SRC_PATH	= ./src/
SRC			= main.c\
			verifs.c\
			cmd.c\
			push_swap.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_PATH 	= libft/
LIBFT_NAME	= libft
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all:		$(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH): 
			@mkdir $(OBJ_PATH)

$(LIBFT):
			@make -sC $(LIBFT_PATH) --no-print-directory
			@echo "Libft \033[1;32mOK\033[m"

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) 
						@echo "Push_swap \033[1;32mOK\033[m"

clean:
			@rm -rf $(OBJ_PATH)
			@make clean -C $(LIBFT_PATH) --no-print-directory

fclean:
			@rm -rf $(NAME)
			@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)

re:			fclean all