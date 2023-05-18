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

NAME = libftprintf.a
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -I
INCLUDE		=	include
SRCS_DIR	=	src/
OBJS_DIR	=	obj/
LIBFT		=	libft

SRC_FILES	=	$(shell find $(SRCS_DIR) -name 'ft_*.c' | cut -d/ -f2 | cut -d. -f1)
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJSF		=	.cache_exists
NORME_ME	=	norminette -R CheckForbiddenSourceHeader

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

all:		$(NAME)

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)My Printf compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
			rm -rf $(OBJS_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: 	clean
			rm -rf $(NAME)
			rm -rf $(LIBFT)/libft.a
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: 		fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"
