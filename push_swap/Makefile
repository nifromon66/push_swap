# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 16:15:03 by nifromon          #+#    #+#              #
#    Updated: 2025/01/06 16:35:13 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# arguments
NAME =				push_swap
BONUS_NAME =		checker
CC =				gcc
CFLAGS =			-Wall -Werror -Wextra
INCLUDES =			-I $(HEADER_DIR)/

# directories
SRC_DIR =			src
UTILS_DIR =			utils
HEADER_DIR =		headers
OBJ_DIR =			obj

BONUS_DIR =			bonus
BONUS_OBJ_DIR = 	obj_bonus

LIBFT_DIR =			libft
LIBFT =				libft/libft.a

# utils
RM = 				rm -rf

# sources and objects
SRC =				\
					$(SRC_DIR)/big_bang_theory.c $(SRC_DIR)/algorithm.c \
					$(SRC_DIR)/push_functions.c $(SRC_DIR)/rotate_functions.c \
					$(SRC_DIR)/reverse_rotate_functions.c $(SRC_DIR)/init.c \
					$(SRC_DIR)/swap_functions.c

OBJ =				$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

UTILS_SRC =			\
					$(UTILS_DIR)/Ouroboros_1.c $(UTILS_DIR)/Ouroboros_2.c \
					$(UTILS_DIR)/Ouroboros_3.c $(UTILS_DIR)/Ouroboros_4.c \
					$(UTILS_DIR)/error_manager.c $(UTILS_DIR)/ft_atoi_long.c \
					$(UTILS_DIR)/algorithm_utils.c

UTILS_OBJ =			$(UTILS_SRC:$(UTILS_DIR)/%.c=$(OBJ_DIR)/$(UTILS_DIR)/%.o)

MAIN_SRC =			$(SRC_DIR)/main.c
OBJ_MAIN =			$(MAIN_SRC:$(SRC_DIR)/main.c=$(OBJ_DIR)/$(SRC_DIR)/main.o)

BONUS_SRC =			\
					$(BONUS_DIR)/checker.c \
					$(BONUS_DIR)/silent_push.c $(BONUS_DIR)/silent_swap.c \
					$(BONUS_DIR)/silent_reverse_rotate.c \
					$(BONUS_DIR)/silent_rotate.c

BONUS_OBJ =			$(BONUS_SRC:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

BONUS_MAIN_SRC =	$(BONUS_DIR)/main.c
BONUS_OBJ_MAIN =	$(BONUS_MAIN_SRC:$(BONUS_DIR)/main.c=$(BONUS_OBJ_DIR)/main.o)

# rules and dependencies
all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_MAIN) $(OBJ) $(UTILS_OBJ)
					$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ) $(UTILS_OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_DIR) all

$(OBJ_DIR)/$(SRC_DIR)/main.o: $(SRC_DIR)/main.c
					@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(OBJ_DIR)/$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(UTILS_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

bonus:				$(BONUS_NAME)

$(BONUS_NAME):		$(LIBFT) $(BONUS_OBJ_MAIN) $(BONUS_OBJ) $(OBJ) $(UTILS_OBJ)
					$(CC) $(CFLAGS) $(BONUS_OBJ_MAIN) $(OBJ) $(UTILS_OBJ) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)/main.o: $(BONUS_DIR)/main.c
					@mkdir -p $(BONUS_OBJ_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
					@mkdir -p $(BONUS_OBJ_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(BONUS_OBJ_DIR)/$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(BONUS_OBJ_DIR)/$(OBJ_DIR)/$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
					@mkdir -p $(OBJ_DIR)/$(UTILS_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@


clean:
					make -C $(LIBFT_DIR) clean
					$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_DIR) fclean
					$(RM) $(NAME) $(BONUS_NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re


