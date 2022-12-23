CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = get_next_line.a

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
