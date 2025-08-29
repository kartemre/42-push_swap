# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/29 15:28:39 by ekart             #+#    #+#              #
#    Updated: 2025/08/29 17:08:06 by ekart            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
INCLUDES:= -Iinc

SRC_DIR := src
SRCS    := $(SRC_DIR)/stack.c \
           $(SRC_DIR)/ops.c \
           $(SRC_DIR)/main.c
OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c inc/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) demo

re: fclean all

demo: CFLAGS+=-DTEST_DEMO
demo: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o demo

.PHONY: all clean fclean re demo
