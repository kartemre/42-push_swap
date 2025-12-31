# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/29 15:28:39 by ekart             #+#    #+#              #
#    Updated: 2025/12/30 20:05:43 by ekart            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
INCLUDES:= -Iinc -I42-Libft

LIBFT_DIR := 42-Libft
LIBFT     := $(LIBFT_DIR)/libft.a

SRC_DIR := src
SRCS    := $(SRC_DIR)/stack.c \
           $(SRC_DIR)/stack_swap.c \
           $(SRC_DIR)/stack_ops.c \
           $(SRC_DIR)/stack_utils.c \
           $(SRC_DIR)/ops_swap.c \
           $(SRC_DIR)/ops_push.c \
           $(SRC_DIR)/ops_rotate.c \
           $(SRC_DIR)/ops_rrotate.c \
           $(SRC_DIR)/parse.c \
           $(SRC_DIR)/parse_utils.c \
           $(SRC_DIR)/sort_small.c \
           $(SRC_DIR)/sort_big.c \
           $(SRC_DIR)/main.c
OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c inc/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) demo
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re demo
