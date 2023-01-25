# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayongja <sayongja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 11:47:25 by jnho              #+#    #+#              #
#    Updated: 2023/01/25 21:39:38 by sayongja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LDIBS = ./libft/libft.a
NAME = pipex

BONUS_SRCS = ./bonus/pipex_bonus.c \
			./bonus/pipex_error_control_bonus.c \
			./bonus/pipex_execute_cmd_line_bonus.c \
			./bonus/pipex_set_cmd_line_bonus.c \
			./bonus/pipex_set_fd_list_bonus.c \
			./bonus/get_next_line/get_next_line.c \
			./bonus/get_next_line/get_next_line_utils.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

MAN_SRCS =  ./mandatory/pipex.c \
			./mandatory/pipex_execute_cmd_line.c \
			./mandatory/pipex_set_cmd_line.c \
			./mandatory/pipex_error_control.c
MAN_OBJS = ${MAN_SRCS:.c=.o}

ifdef BONUS
	SRCS = $(BONUS_SRCS)
	OBJS = $(BONUS_OBJS)
else
	SRCS = $(MAN_SRCS)
	OBJS = $(MAN_OBJS)
endif

all: $(NAME)

bonus :
	make BONUS=1 all

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

.PHONY: all clean fclean re bonus