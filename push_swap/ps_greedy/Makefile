CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ps_greedy.c ps_greedy_partitioning.c ps_greedy_move_element.c \
		ps_greedy_rotate_a_table.c ps_greedy_cmd_table.c quick_sort.c \
		ps_greedy_sort_three_element.c ps_greedy_sort_four_element.c
OBJS = ${SRCS:.c=.o}
NAME = ps_greedy.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -c

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
