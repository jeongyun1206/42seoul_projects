CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = deque_ele_func.c deque_info_func.c deque_init_func.c
OBJS = ${SRCS:.c=.o}
NAME = deque.a

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
