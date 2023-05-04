# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 14:22:12 by ilymegy           #+#    #+#              #
#    Updated: 2023/05/02 14:22:36 by ilymegy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
CC = gcc -Wall -Wextra -Werror
SRC = $(shell find . -name 'ft_*' '!' -iname 'ft_lst*')
SRC_BONUS = $(shell find . -name 'ft_lst*')
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME).a $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME).a $(NAME).so

re: fclean all

bonus : $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME).a $(OBJS) $(OBJS_BONUS)
