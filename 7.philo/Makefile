# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 11:15:57 by ilymegy           #+#    #+#              #
#    Updated: 2023/11/18 11:15:59 by ilymegy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philosophers
CC			= cc
CFLAGS		= -Wall -Wextra -Werror #-g3

INC			= -I ./mandatory/inc/

SRC_PATH	= ./mandatory/src/
SRC			= main.c\
			check_args.c\
			init_philo_struct.c\
			handle_forks.c\
			time.c\
			threads.c\
			life.c\
			actions.c\
			utils.c\
			style.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= mandatory/obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all:		$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
$(OBJS): 	$(OBJ_PATH)
$(OBJ_PATH): 
			@mkdir $(OBJ_PATH)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC) 
						@echo "philosophers \033[1;32mOK\033[m"

clean:
			@rm -rf $(OBJ_PATH)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all