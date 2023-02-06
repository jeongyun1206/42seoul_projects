# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 16:09:44 by jnho              #+#    #+#              #
#    Updated: 2023/02/06 18:29:12 by jnho             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LDIBS = ./ft_printf/libftprintf.a
SRCS =  main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		execute_cmds/minishell_execute_utils.c \
		execute_cmds/minishell_fds_functions.c \
		execute_cmds/minishell_utils.c \
		execute_cmds/minshell_execute_cmd.c \
		built_in_cmds/cd_cmd.c \
		built_in_cmds/echo_cmd.c \
		built_in_cmds/env_cmd.c \
		built_in_cmds/env_list.c \
		built_in_cmds/env_list_utils.c \
		built_in_cmds/exit_cmd.c \
		built_in_cmds/export_cmd.c \
		built_in_cmds/pwd_cmd.c \
		built_in_cmds/unset_cmd.c \
		parser/parse.c \
		parser/token.c
OBJS = $(SRCS:.c=.o)
NAME = minishell

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./ft_printf all
	$(CC) $(CFLAGS) -g $(SRCS) $(LDIBS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	make -C ./ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re