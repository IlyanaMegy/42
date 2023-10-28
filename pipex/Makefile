# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 11:53:13 by ilymegy           #+#    #+#              #
#    Updated: 2023/09/20 23:16:39 by ilymegy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex
NAME_BONUS	= pipex_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3

INC			= -I ./mandatory/inc/\
			-I ./libft/

INC_BONUS	= -I ./bonus/inc/\
			-I ./libft/
			
SRC_PATH	= ./mandatory/src/
SRC			= main.c\
			utils.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

SRC_PATH_B	= ./bonus/src/
SRC_B		= main.c\
			utils.c\
			open_close.c
SRCS_B		= $(addprefix $(SRC_PATH_B), $(SRC_B))

OBJ_PATH	= mandatory/obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

OBJ_PATH_B	= bonus/obj/
OBJ_B		= $(SRC_B:.c=.o)
OBJS_B		= $(addprefix $(OBJ_PATH_B), $(OBJ_B))

LIBFT_PATH 	= libft/
LIBFT_NAME	= libft
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

all:		$(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH): 
			@mkdir $(OBJ_PATH)

$(OBJ_PATH_B)%.o: $(SRC_PATH_B)%.c 
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC_BONUS)

$(OBJS_B): $(OBJ_PATH_B)

$(OBJ_PATH_B): 
			@mkdir $(OBJ_PATH_B)

$(NAME_BONUS):	$(OBJS_B)
			@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_B) $(LIBFT) $(INC_BONUS) 
						@echo "pipex bonus \033[1;32mOK\033[m"

$(LIBFT):
			@make -sC $(LIBFT_PATH) --no-print-directory
			@echo "Libft \033[1;32mOK\033[m"

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) 
						@echo "pipex \033[1;32mOK\033[m"

clean:
			@rm -rf $(OBJ_PATH) $(OBJ_PATH_B)
			@make clean -C $(LIBFT_PATH) --no-print-directory

fclean:		clean
			@rm -rf $(NAME) $(NAME_BONUS)
			@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)

re:			fclean all

bonus :		$(LIBFT) $(NAME_BONUS)

