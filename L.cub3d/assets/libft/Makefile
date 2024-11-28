# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 04:59:09 by ltorkia           #+#    #+#              #
#    Updated: 2024/07/03 18:51:59 by ltorkia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		libft.a


#########################################################
#############             STRUCTURE           ###########
#########################################################

SRCS_DIR			= 	srcs
INC_DIR				= 	inc
OBJS_DIR			= 	objs


#########################################################
#############              SOURCES            ###########
#########################################################

FUNC_DIR		= 	${SRCS_DIR}
FUNC_SRCS		= 	ft_atoi.c		ft_bzero.c			ft_calloc.c		ft_isalnum.c	ft_isalpha.c		ft_isascii.c \
					ft_isdigit.c	ft_isspace.c		ft_isprint.c	ft_itoa.c		ft_memchr.c			ft_memcmp.c \
					ft_memcpy.c		ft_memmove.c		ft_memset.c		ft_putchar_fd.c	ft_putendl_fd.c		ft_putnbr_fd.c \
					ft_putstr_fd.c	ft_split.c			ft_strchr.c		ft_strdup.c		ft_striteri.c		ft_strjoin.c \
					ft_strlcat.c	ft_strlcpy.c		ft_strlen.c		ft_strmapi.c	ft_strncmp.c		ft_strnstr.c \
					ft_strrchr.c	ft_strtrim.c		ft_substr.c		ft_tolower.c	ft_toupper.c		ft_print_char.c \
					ft_print_hex.c	ft_print_int.c		ft_print_ptr.c	ft_print_str.c	ft_print_unsigned.c	ft_printf.c \
					ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
					ft_lstclear.c	ft_lstiter.c		ft_lstmap.c		get_next_line.c	get_next_line_fd.c

FUNC_FILES		= 	${addprefix ${FUNC_DIR}/,${FUNC_SRCS}}


#########################################################
#############         COMPILATION            ############
#########################################################

SRCS				= 	${FUNC_FILES}
OBJS				= 	${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
DEPS				=	${OBJS:.o=.d}

CC					= 	cc
CFLAGS				= 	-Wall -Wextra -Werror
INC_FLAGS			= 	${addprefix -I ,${INC_DIR}}
AR					= 	ar -rcs

RM					= 	rm -rf


#########################################################
#############             RULES               ###########
#########################################################

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${dir $@}
	${CC} -MMD -c ${CFLAGS} ${INC_FLAGS} $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS_DIR}

fclean:	clean
	${RM} ${NAME}

re: fclean
	@$(MAKE) all

#-----> INCLUDE DEPENDENCIES
-include: ${DEPS}

.PHONY: all clean fclean re