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

NAME 		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3

INC			= -I ./inc/\
			-I ./libft/
			
SRC_PATH	= ./src/
SRC			= main.c\
			init.c\
			init_stack_a.c\
			sort_tools.c\
			quick_sort.c\
			utils.c\
			push_swap.c\
			smol_sort.c\
			moves.c\
			half_to_b.c\
			return_to_a.c\
			return_to_a_sorting.c\
			smart_rotate.c\
			reduce_instr.c
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
						@echo "push_swap \033[1;32mOK\033[m"

clean:
			@rm -rf $(OBJ_PATH)
			@make clean -C $(LIBFT_PATH) --no-print-directory

fclean:		clean
			@rm -rf $(NAME)
			@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)

re:			fclean all