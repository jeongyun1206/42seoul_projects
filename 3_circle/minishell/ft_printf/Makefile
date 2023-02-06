CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS =  ft_printf_form1.c ft_printf_form2.c ft_printf.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft all
	cp ./libft/libft.a libftprintf.a
	ar -rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -c

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean:	clean
	rm -rf ${NAME}
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
