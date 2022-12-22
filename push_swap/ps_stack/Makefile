CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ps_stack_cmd_rotate.c ps_stack_cmd_swap.c ps_stack_cmd_push.c ps_stack_init_func.c ps_stack_cmd_reverse_rotate.c
OBJS = ${SRCS:.c=.o}
NAME = ps_stack.a

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
