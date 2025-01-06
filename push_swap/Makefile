# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 01:35:07 by nifromon          #+#    #+#              #
#    Updated: 2025/01/06 03:38:42 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the programm
NAME =			push_swap
NAME_BONUS =	checker

# Compilation
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror

# Link editor
LDFLAGS =		-L $(LIBFT_DIR) -lft

# Utils
AR =			ar -rcs
RM =			rm -rf

# Repositories
INC_DIR =		./headers
SRC_DIR =		./src
UTILS_DIR =		./utils

LIBFT_DIR =		$(INC_DIR)/libft
LIBFT =			$(LIBFT_DIR)/libft.a

BONUS_DIR =		./bonus

OBJ_DIR =		./obj
OBJ_MAIN_DIR =	$(OBJ_DIR)/main

OBJ_BONUS_DIR =	$(OBJ_DIR)/bonus

# Sources and objects files
SRCS =			\
				$(SRC_DIR)/main.c $(SRC_DIR)/init.c \
				$(SRC_DIR)/big_bang_theory.c $(SRC_DIR)/algorithm.c \
				$(SRC_DIR)/reverse_rotate_functions.c \
				$(SRC_DIR)/rotate_functions.c \
				$(SRC_DIR)/push_functions.c $(SRC_DIR)/swap_functions.c \
				\
				$(UTILS_DIR)/algorithm_utils.c $(UTILS_DIR)/error_manager.c \
				$(UTILS_DIR)/ft_atoi_long.c \
				$(UTILS_DIR)/Ouroboros_1.c $(UTILS_DIR)/Ouroboros_2.c \
				$(UTILS_DIR)/Ouroboros_3.c $(UTILS_DIR)/Ouroboros_4.c

OBJ_MAIN =		${SRCS:$(SRC_DIR)/%.c=$(OBJ_MAIN_DIR)/%.o}
OBJ_MAIN =		${OBJ_MAIN}${SRCS:$(UTILS_DIR)/%.c=$(OBJ_MAIN_DIR)/%.o}

# Rules and dependencies
all: 			$(NAME)
				$(NAME): 		$(LIBFT) $(OBJ_MAIN_DIR) $(OBJ_MAIN)
								$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
						
				$(LIBFT):
								make -C $(LIBFT_DIR) all
						
				$(OBJ_MAIN_DIR)/%.o: $(SRC_DIR)/%.c
								@mkdir -p $(OBJ_MAIN_DIR)
								$(CC) -c $(CFLAGS) $< -o $@
						
				$(OBJ_MAIN_DIR)/%.o: $(UTILS_DIR)/%.c
								@mkdir -p $(OBJ_MAIN_DIR)
								$(CC) -c $(CFLAGS) $< -o $@

bonus:			$(NAME_BONUS)
				$(NAME_BONUS):	$(LIBFT) $(OBJ_BONUS_DIR) $(OBJ_BONUS)
								$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
						
				$(LIBFT):
								make -C $(LIBFT_DIR) all
						
				$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
								@mkdir -p $(OBJ_BONUS_DIR)
								$(CC) $(CFLAGS) -c $< -o $@

				$(OBJ_BONUS_DIR)/%.o: $(SRC_DIR)/%.c
								@mkdir -p $(OBJ_BONUS_DIR)
								$(CC) $(CFLAGS) -c $< -o $@

				$(OBJ_BONUS_DIR)/%.o: $(UTILS_DIR)/%.c
								@mkdir -p $(OBJ_BONUS_DIR)
								$(CC) $(CFLAGS) -c $< -o $@		

clean:
				make -C $(LIBFT_DIR) clean
				rm -rf $(OBJ_DIR)

fclean: 		clean
				make -C $(LIBFT_DIR) fclean
				rm -f $(NAME) $(NAME_BONUS)

re: 			fclean all

.PHONY: 		all bonus clean fclean re
									
						
