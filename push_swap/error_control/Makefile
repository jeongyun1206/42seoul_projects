CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = error_control.c
OBJS = ${SRCS:.c=.o}
NAME = error_control.a 

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
