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

NAME = libftprintf
CC = gcc -Wall -Wextra -Werror
SRC = $(shell find . -name 'ft_*')
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME).a $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME).a

re: fclean all
