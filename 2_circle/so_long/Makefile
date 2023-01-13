# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:52:25 by jnho              #+#    #+#              #
#    Updated: 2023/01/13 12:02:59 by jnho             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
LDIBS = ./libft/libft.a ./ft_printf/libftprintf.a
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNL_OBJS = ${GNL_SRCS:.c=.o}
NAME = so_long

BONUS_SRCS = ./bonus/sl_map_parsing_bonus.c ./bonus/sl_map_parsing_cofrim_map_valid_bonus.c \
			./bonus/sl_mlx_bonus.c ./bonus/sl_mlx_key_hook_functions_bonus.c \
			./bonus/sl_mlx_key_hook_move_functions.c ./bonus/sl_mlx_loop_hook_functions.c\
			./bonus/so_long_bonus.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

MAN_SRCS = ./mandatory/so_long.c ./mandatory/sl_map_parsing.c \
		./mandatory/sl_map_parsing_cofrim_map_valid.c \
		./mandatory/sl_mlx.c ./mandatory/sl_mlx_key_hook_functions.c
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
	make -C ./ft_printf all
	$(CC) $(CFLAGS) -g $(CLIB) $(SRCS) $(GNL_SRCS) $(LDIBS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $< -c -o $@

bonus :
	make BONUS=1 all

clean:
	make -C ./libft clean
	make -C ./ft_printf clean
	rm -f $(MAN_OBJS) $(BONUS_OBJS) $(GNL_OBJS)

fclean: clean
	make -C ./libft fclean
	make -C ./ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus