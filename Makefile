# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apineda <apineda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/24 15:18:09 by apineda           #+#    #+#              #
#    Updated: 2017/05/24 15:20:36 by apineda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FILENAMES = ft_filler ft_zone_map ft_save_piece ft_place_piece ft_print_map
INCLUDE_DIR = ./inc

CC = gcc

CCFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
INC = $(INCLUDE_DIR)
LIBFT = ./libft
LIBFT_A = libft.a
LIBFT_ALL = $(LIBFT)/$(LIBFT_A) 

SRC_1 = $(addprefix src/, $(addsuffix .c, $(FILENAMES)))

all: $(NAME)

$(NAME): $(SRC_1)
	@make -C libft
	@echo "\033[32mCompiled libft\033[0m"
	@$(CC) $(CCFLAGS) -I $(INC) -I $(LIBFT)/includes $(LIBFT_ALL) $(SRC_1) -o $(NAME)
	@echo "\033[32m$(NAME) compiled\033[0m"

clean:
	@make -C libft clean
	@echo "\033[31;1m libs cleaned\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "\033[31;1m$(NAME) and libs fcleaned\033[0m"

re: fclean all

.PHONY: clean

