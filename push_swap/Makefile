# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/15 22:07:14 by nifromon          #+#    #+#              #
#    Updated: 2024/12/16 16:31:43 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				push_swap.a

CC =				gcc
CFLAGS =			-Wall -Werror -Wextra

SRCS_DIR =			.
OBJS_DIR =			obj

AR =				ar -rcs
RM =				rm -rf

LIBFT_PATH =		./libft
LIBFT =				$(LIBFT_PATH)/libft.a

SRCS =				\
					$(SRCS_DIR)/error_manager.c $(SRCS_DIR)/dclst_utils.c \
					$(SRCS_DIR)/push_swap.c $(SRCS_DIR)/reverse_rotate.c \
					$(SRCS_DIR)/rotate.c $(SRCS_DIR)/push.c $(SRCS_DIR)/swap.c \
					$(SRCS_DIR)/swap_utils.c

OBJS = 				${SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o}

all:				$(NAME)

$(NAME): 			$(LIBFT) $(OBJS_DIR) $(OBJS)
					cp $(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)
					
$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)
					
$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c 
					$(CC) -c $(CFLAGS) $< -o $@

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re