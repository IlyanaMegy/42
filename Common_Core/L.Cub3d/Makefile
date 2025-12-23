# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 04:59:09 by ltorkia           #+#    #+#              #
#    Updated: 2024/07/03 18:52:17 by ltorkia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= 		cub3D
B_NAME				= 		cub3D_bonus


#########################################################
#############             STRUCTURE           ###########
#########################################################

SRCS_DIR			= 	srcs
INC_DIRS			= 	inc		assets/minilibx		assets/libft/inc
LIB_DIR				= 	assets

OBJS_DIR			= 	objs
B_OBJS_DIR			= 	objs_bonus


#########################################################
#############              SOURCES            ###########
#########################################################

MAIN_FUNC_DIR		= 	${SRCS_DIR}
MAIN_FUNC_SRCS		= 	cub3D.c

EXIT_FUNC_DIR		= 	${SRCS_DIR}/exit
EXIT_FUNC_SRCS		= 	clean_utils.c		clean.c				error.c

INIT_FUNC_DIR		= 	${SRCS_DIR}/init
INIT_FUNC_SRCS		= 	init_data.c			init_textures.c		textures.c

MOVE_FUNC_DIR		= 	${SRCS_DIR}/move
MOVE_FUNC_SRCS		= 	inputs.c			player_dir.c		player_move.c	player_pos.c		player_rotate.c
B_MOVE_FUNC_SRCS	= 	inputs_bonus.c		player_dir.c		player_move.c	player_pos.c		player_rotate.c

PARSING_FUNC_DIR	= 	${SRCS_DIR}/parsing
PARSING_FUNC_SRCS	= 	check_file.c		check_map_utils.c	check_map.c		create_map_utils.c	create_map.c \
						parse_infos_utils.c	parse_infos.c		parser_utils.c	parser.c			utils.c	debug.c

RENDER_FUNC_DIR		= 	${SRCS_DIR}/render
RENDER_FUNC_SRCS	= 	render.c			raycasting.c
B_RENDER_FUNC_SRCS	= 	render_bonus.c		raycasting.c		minimap_image.c	minimap_pixels.c	render_minimap.c

#-----> MANDATORY
MOVE_FILES			= 	${addprefix ${MOVE_FUNC_DIR}/,${MOVE_FUNC_SRCS}}
RENDER_FILES		= 	${addprefix ${RENDER_FUNC_DIR}/,${RENDER_FUNC_SRCS}}

#-----> BONUS FILES
B_MOVE_FILES		= 	${addprefix ${MOVE_FUNC_DIR}/,${B_MOVE_FUNC_SRCS}}
B_RENDER_FILES		= 	${addprefix ${RENDER_FUNC_DIR}/,${B_RENDER_FUNC_SRCS}}

#-----> USED FOR BOTH
MAIN_FILES			= 	${addprefix ${MAIN_FUNC_DIR}/,${MAIN_FUNC_SRCS}}
EXIT_FILES			= 	${addprefix ${EXIT_FUNC_DIR}/,${EXIT_FUNC_SRCS}}
INIT_FILES			= 	${addprefix ${INIT_FUNC_DIR}/,${INIT_FUNC_SRCS}}
PARSING_FILES		= 	${addprefix ${PARSING_FUNC_DIR}/,${PARSING_FUNC_SRCS}}


#########################################################
#############            LIBRARIES            ###########
#########################################################

LIBFT				= 	${LIB_DIR}/libft/libft.a
MINILIBX			= 	${LIB_DIR}/minilibx/libmlx.a

MY_LIBS				= 	${LIBFT} ${MINILIBX}

MY_LIBS_FLAGS		= 	${foreach lib,${MY_LIBS},${addprefix -L ,${dir ${lib}}} \
				  		${addprefix -l,${patsubst lib%.a,%,${notdir ${lib}}}}}
GEN_LIBS_FLAGS		= 	-lXext -lX11 -lm


#########################################################
#############         COMPILATION            ############
#########################################################

SRCS				= 	${MAIN_FILES} ${EXIT_FILES} ${INIT_FILES} ${MOVE_FILES} \
				  		${PARSING_FILES} ${RENDER_FILES}
OBJS				= 	${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
DEPS				= 	${OBJS:.o=.d}

B_SRCS				= 	${MAIN_FILES} ${EXIT_FILES} ${INIT_FILES} ${B_MOVE_FILES} \
				  		${PARSING_FILES} ${B_RENDER_FILES}
B_OBJS				= 	${B_SRCS:${SRCS_DIR}/%.c=${B_OBJS_DIR}/%.o}
B_DEPS				= 	${B_OBJS:.o=.d}

CC					= 	cc
CFLAGS				= 	-Wall -Wextra -Werror
INC_FLAGS			= 	${addprefix -I ,${INC_DIRS}}
LIB_FLAGS			= 	${MY_LIBS_FLAGS} ${GEN_LIBS_FLAGS}

RM					= 	rm -rf


#########################################################
#############            COLORS               ###########
#########################################################

GREEN				= \033[1;32m
CYAN				= \033[1;36m
RESET				= \033[0m


#########################################################
#############             RULES               ###########
#########################################################

#-----> OBJS COMPILATION (MANDATORY + BONUS)

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${dir $@}
	@echo "\n${GREEN}--> Compiling $<${RESET}"
	${CC} -MMD -c ${CFLAGS} ${INC_FLAGS} $< -o $@

${B_OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${dir $@}
	@echo "\n${GREEN}--> Compiling $< for bonus${RESET}"
	${CC} -MMD -c ${CFLAGS} ${INC_FLAGS} $< -o $@


#-----> MANDATORY

all: ${NAME}

${NAME}: ${LIBFT} ${MINILIBX} ${OBJS}
	@echo "\n"
	@echo "${CYAN}#######################################################${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}####                    LINKING                    ####${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}#######################################################${RESET}\n"
	@echo "${GREEN}--> ${NAME}${RESET}\n"
	${CC} ${INC_FLAGS} ${OBJS} ${LIB_FLAGS} -o ${NAME}


#-----> BONUS

bonus: ${B_NAME}

${B_NAME}: ${LIBFT} ${MINILIBX} ${B_OBJS}
	@echo "\n"
	@echo "${CYAN}#######################################################${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}####                    LINKING                    ####${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}#######################################################${RESET}\n"
	@echo "${GREEN}--> ${B_NAME}${RESET}\n"
	${CC} ${INC_FLAGS} ${B_OBJS} ${LIB_FLAGS} -o ${B_NAME}


#-----> LIBRARIES

${LIBFT}:
	@echo "\n"
	@echo "${CYAN}#######################################################${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}####               BUILDING LIBFT                  ####${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}#######################################################${RESET}\n"
	@make -C ${dir ${LIBFT}}

${MINILIBX}:
	@echo "\n"
	@echo "${CYAN}#######################################################${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}####              BUILDING MINILIBX                ####${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}#######################################################${RESET}\n"
	@make -C ${dir ${MINILIBX}}


#-----> CLEANING / RECOMPILATION

clean:
	@echo "\n"
	@echo "${CYAN}#######################################################${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}####                  CLEANING                     ####${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}#######################################################${RESET}\n"
	@make -C ${dir ${LIBFT}} clean
	@make -C ${dir ${MINILIBX}} clean
	${RM} ${OBJS_DIR}
	${RM} ${B_OBJS_DIR}

fclean:
	@echo "\n"
	@echo "${CYAN}#######################################################${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}####                 FULL CLEAN                    ####${RESET}"
	@echo "${CYAN}####                                               ####${RESET}"
	@echo "${CYAN}#######################################################${RESET}\n"
	@make -C ${dir ${LIBFT}} fclean
	@make -C ${dir ${MINILIBX}} clean
	${RM} ${OBJS_DIR}
	${RM} ${B_OBJS_DIR}
	${RM} ${NAME} ${B_NAME}

re: fclean
	@$(MAKE) all


#-----> INCLUDE DEPENDENCIES

-include ${DEPS}
-include ${B_DEPS}

.PHONY: all bonus clean fclean re
