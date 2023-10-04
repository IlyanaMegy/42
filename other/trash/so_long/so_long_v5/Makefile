NAME		= so_long.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

MLX_PATH    = minilibx/
MLX_NAME    = libmlx.a
MLX         = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH 	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC			=	-I ./inc/\
			-I ./libft/\
			-I ./minilibx/

SRC_PATH	= ./src/
SRC			= main.c \
			close_me.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all:		$(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH): 
			@mkdir $(OBJ_PATH)

$(MLX):
			@make -sC $(MLX_PATH) --no-print-directory
			@echo "MiniLibX \033[1;32mOK\033[m"

$(LIBFT):
			@make -sC $(LIBFT_PATH) --no-print-directory
			@echo "Libft \033[1;32mOK\033[m"

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
			@echo "So Long \033[1;32mOK\033[m"

clean:
			@rm -rf $(OBJ_PATH)
			@make clean -C $(MLX_PATH) --no-print-directory
			@make clean -C $(LIBFT_PATH) --no-print-directory

fclean:
			@rm -rf $(NAME)
			@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)

re:			fclean all


# NAME    = fractol

# CC        = gcc
# CFLAGS    = -Werror -Wextra -Wall -g

# MLX_PATH    = minilibx-linux/
# MLX_NAME    = libmlx.a
# MLX            = $(MLX_PATH)$(MLX_NAME)

# LIBFT_PATH    = libft/
# LIBFT_NAME    = libft.a
# LIBFT        = $(LIBFT_PATH)$(LIBFT_NAME)

# INC            =    -I ./includes/\
#                 -I ./libft/\
#                 -I ./minilibx-linux/

# SRC_PATH    =    src/
# SRC            =    fractol.c \
#                 initialization.c \
#                 utils.c \
#                 events.c \
#                 render.c \
#                 color.c \
#                 parse_args.c \
#                 help_msg.c \
#                 fractal_sets/mandelbrot.c \
#                 fractal_sets/julia.c \
#                 fractal_sets/mandelbox.c \
#                 color_utils.c
# SRCS        = $(addprefix $(SRC_PATH), $(SRC))

# OBJ_PATH    = obj/
# OBJ            = $(SRC:.c=.o)
# OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))

# all: $(MLX) $(LIBFT) $(NAME)

# $(OBJ_PATH)%.o: $(SRC_PATH)%.c
#     @$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# $(OBJS): $(OBJ_PATH)

# $(OBJ_PATH):
#     @mkdir $(OBJ_PATH)
#     @mkdir $(OBJ_PATH)fractal_sets/
#     @mkdir $(OBJ_PATH)color_schemes/

# $(MLX):
#     @make -sC $(MLX_PATH) --no-print-directory
#     @echo "MiniLibX \033[1;32mOK\033[m"

# $(LIBFT):
#     @make -sC $(LIBFT_PATH) --no-print-directory
#     @echo "Libft \033[1;32mOK\033[m"

# $(NAME): $(OBJS)
#     @$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
#     @echo "Fractol \033[1;32mOK\033[m"

# bonus: all

# clean:
#     @rm -rf $(OBJ_PATH)
#     @make clean -C $(MLX_PATH) --no-print-directory
#     @make clean -C $(LIBFT_PATH) --no-print-directory

# fclean: clean
#     @rm -f $(NAME)
#     @rm -f $(LIBFT_PATH)$(LIBFT_NAME)