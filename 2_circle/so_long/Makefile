# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:52:25 by jnho              #+#    #+#              #
#    Updated: 2023/01/11 12:55:18 by jnho             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
SRCS = so_long.c sl_map_parcing.c sl_map_parcing_cofrim_map_valid.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
LDIBS = ./libft/libft.a
OBJS = ${SRCS:.c=.o}
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft all
	$(CC) $(CFLAGS) -g $(CLIB) $(SRCS) $(LDIBS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) $< -c -o $@

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re