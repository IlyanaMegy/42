# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 11:53:13 by ilymegy           #+#    #+#              #
#    Updated: 2023/05/12 11:53:14 by ilymegy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror 
INCLUDE		=	-I includes\
				-I libft

OBJS_DIR	=	obj/
OBJ			=	$(SRC_FILES:.c=.o)
OBJS        =	$(addprefix $(OBJS_DIR), $(OBJ))

SRCS_DIR	=	src/
SRC_FILES	=	$(shell find $(SRCS_DIR) -name '*.c' | cut -d/ -f2)
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC_FILES))

LIBFT_PATH	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)

# RAINBOOOW

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:		$(LIBFT) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c 
			@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS): $(OBJS_DIR)

$(OBJS_DIR): 
			@mkdir $(OBJS_DIR)

$(LIBFT):
			@make -sC $(LIBFT_PATH) --no-print-directory
			@echo "Libft \033[1;32mOK\033[m"

$(NAME):    $(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDE) 
			@echo "$(GREEN)My Printf compiled!$(DEF_COLOR)"

clean:
			@rm -rf $(OBJS_DIR)
			@make clean -C $(LIBFT_PATH) --no-print-directory

fclean:        clean
			@rm -rf $(NAME)
			@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)

re:         fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"
