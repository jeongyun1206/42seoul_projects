# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 11:47:25 by jnho              #+#    #+#              #
#    Updated: 2023/01/19 16:50:43 by jnho             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LDIBS = ./libft/libft.a
NAME = pipex

BONUS_SRCS = 
BONUS_OBJS =

MAN_SRCS =  pipex.c \
			pipex_execute_cmd_line.c \
			pipex_set_cmd_line.c \
			pipex_error_control.c
MAN_OBJS = ${MAN_SRCS:.c=.o}

ifdef BONUS
	SRCS = $(BONUS_SRCS)
	OBJS = $(BONUS_OBJS)
else
	SRCS = $(MAN_SRCS)
	OBJS = $(MAN_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft all
	$(CC) $(CFLAGS) -g $(SRCS) $(LDIBS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $< -c -o $@


clean:
	make -C ./libft clean
	rm -f $(MAN_OBJS) $(BONUS_OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus%