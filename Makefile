# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 06:04:01 by mdegache          #+#    #+#              #
#    Updated: 2025/07/15 09:04:57 by mdegache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[31m
GREEN=\033[32m
PURPLE=\033[35m
RESET=\033[0m

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lSDL2

LIB = includes/libft
LIBFT = includes/libft/libft.a includes/MacroLibX/libmlx.so

SRC = src/main.c

OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(SRC) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)SUCCESS$(RESET)"

$(LIBFT):
	@$(MAKE) -s -C $(LIB) bonus

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIB) clean
	@echo "$(PURPLE)CLEAN$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIB) fclean
	@echo "$(RED)FCLEAN$(RESET)"

re: fclean all

.PHONY : all clean fclean re