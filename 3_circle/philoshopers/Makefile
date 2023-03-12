# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 13:52:13 by jnho              #+#    #+#              #
#    Updated: 2023/03/12 15:01:28 by jnho             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = philo
SRCS = philo.c philo_routine_function.c philo_routine.c philo_setting.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re% 