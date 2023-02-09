# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 16:09:44 by jnho              #+#    #+#              #
#    Updated: 2023/02/09 14:30:14 by jnho             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include 
LDIBS = ./ft_printf/libftprintf.a
SRCS =  main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		execute_cmds/minishell_execute_utils.c \
		execute_cmds/minishell_fds_functions.c \
		execute_cmds/minishell_fds_utils.c \
		execute_cmds/minishell_here_doc.c \
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
		parser/token.c \
		parser/utils.c
OBJS = $(SRCS:.c=.o)
NAME = minishell
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./ft_printf all
	$(CC) $(CFLAGS) $(LINKING_FLAGS) -g $(SRCS) $(LDIBS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) $< -c -o $@

clean:
	make -C ./ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re