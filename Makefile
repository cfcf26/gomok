# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 02:58:47 by ekwak             #+#    #+#              #
#    Updated: 2023/05/05 11:57:19 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
LIBS = -lmlx -framework OpenGL -framework AppKit
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
BIN = gomoku
LIB_MLX_DIR = minilibx_opengl_20191021

SRC_FILES = main.c \
			graphics/display.c \
			graphics/init_graphics_context.c \
			graphics/mouse_events.c \
			#utils/init_board.c \

OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

all: $(BIN)

$(BIN): $(OBJ_FILES)
	@$(MAKE) -C $(LIB_MLX_DIR)
	$(CC) $(CFLAGS) -I$(LIB_MLX_DIR) -I$(INC_DIR) -L$(LIB_MLX_DIR) $(OBJ_FILES) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

debug: CFLAGS += $(DEBUG) # DEBUG 플래그 추가
debug: all  # debug 규칙 추가

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)
	@$(MAKE) -C $(LIB_MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
