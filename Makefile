# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 11:26:55 by alanter           #+#    #+#              #
#    Updated: 2018/10/25 20:23:26 by alanter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################## PROJECT ########################

NAME = lem_in 

########################## OS ###########################

OS := $(shell uname)

######################### COLOR #########################

BLUE = \033[1;34m
RED = \033[8m\033[1;31m
GREEN = \033[32m
NORMAL = \033[0m
LINE_ERASER = \n\033[1A\033[0K\r

########################## STR ##########################

STR_SUCCESS = $(GREEN)SUCCESS$(BLUE).\n$(NORMAL)

######################### FLAGS #########################

ifeq ($(OS),Darwin)
	FLAGS_DEFAULT = -g3 -Wall -Werror -Wextra #-fsanitize=address
	FLAGS_MLX = -framework OpenGL -framework Appkit
else 
	FLAGS_DEFAULT = -Wall -Werror -Wextra
	FLAGS_MLX = -L/usr/X11/lib -lXext -lX11 -lm
endif
FLAGS_LIB = -L$(LIBMLX_PATH) -lmlx -L$(LIBFT_PATH)\
			            -lft $(FLAGS_MLX)

####################### LIBRARIES #######################

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a
ifeq ($(OS),Darwin)
	LIBMLX_PATH = ./minilibx_macos/
else 
	LIBMLX_PATH = ./minilibx_x11/
endif
LIBMLX = $(LIBMLX_PATH)libmlx.a

######################## COMMANDS #######################

CC = gcc
MAKE = /usr/bin/make
MOVE = /bin/mv
RM = /bin/rm -f
MKDIR = /bin/mkdir

######################## INCLUDES #######################

INC_DIR = ./includes/ ./libft/includes
ifeq ($(OS),Darwin)
	INC_DIR += ./minilibx
else 
	INC_DIR += ./minilibx_x11
endif
INC_PREF = -I
INC_FILES = ./includes/visual.h
INC = $(addprefix $(INC_PREF), $(INC_DIR))

######################## SOURCES ########################

SRC_PATH = ./srcs/
SRC_FILES =	main.c \
			errors.c \
			find_path.c \
			node.c \
			parsing.c \
			run_through.c \
			tools_algo.c \
			tools_ants.c \
			tools_comments.c \
			tools_common.c \
			tools_links.c \
			tools_rooms.c \
			tools_printants.c \
			window.c \
			draw.c \
			coord.c \
			draw_ants.c \
			menu.c
SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))

######################## OBJECTS ########################

OBJ_PATH = ./objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJS = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
	OBJ_DIR = objs

######################### RULES #########################

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ_DIR) $(OBJS)
	@printf "$(LINE_ERASER)$(RED)$@: $(BLUE)Objects compilation: $(STR_SUCCESS)"
	@printf "$(RED)$@: $(BLUE)Compiling project: $(NORMAL)"
	@$(CC) $(FLAGS_DEFAULT) $(OBJS) $(FLAGS_LIB) -o $@
	@printf "$(STR_SUCCESS)"
	@printf "$(RED)$@: $(GREEN)project ready.$(NORMAL)\n"

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(LIBMLX):
	@printf "$(BLUE)Compiling $(RED)$@$(BLUE): $(NORMAL)"
	@$(MAKE) -C $(LIBMLX_PATH) > .tmp_proj
	@printf "$(GREEN)SUCCESS\n$(NORMAL)"
	@$(RM) .tmp_proj

clean:
	@printf "$(RED)$(NAME): $(BLUE)Cleaning objects: $(NORMAL)"
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(LIBMLX_PATH)
	@printf "$(STR_SUCCESS)"

fclean: clean
	@printf "$(RED)$(NAME): $(BLUE)Cleaning project: $(NORMAL)"
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@printf "$(STR_SUCCESS)"

re: fclean all

$(OBJ_DIR):
	@printf "$(RED)$(NAME): $(BLUE)Create objects folder: $(NORMAL)"
	@mkdir -p $@
	@printf "$(STR_SUCCESS)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_FILES)
	@printf "$(LINE_ERASER)$(RED)$(NAME): $(BLUE)Compiling: $(NORMAL)\"$@\"."
	@$(CC) -o $@ $< $(FLAGS_DEFAULT) -c $(INC)

.PHONY: all clean fclean re
