ifdef BONUS
	NAME = checker
	SRCS = ps_fill_stack.c ./checker/checker.c
	LDLIBS = ./libft/libft.a ./ps_stack/ps_stack.a ./ps_stack/deque/deque.a ./error_control/error_control.a \
			./checker/ft_printf/libftprintf.a ./checker/get_next_line/get_next_line.a
	LDLIBS_DIR = ./libft ./ps_stack ./ps_stack/deque ./error_control ./checker/ft_printf \
			./checker/get_next_line
else
	NAME = push_swap
	SRCS = push_swap.c ps_fill_stack.c
	LDLIBS = ./libft/libft.a ./ps_greedy/ps_greedy.a ./ps_stack/ps_stack.a ./ps_stack/deque/deque.a \
		 ./error_control/error_control.a
	LDLIBS_DIR = ./libft ./ps_greedy ./ps_stack ./ps_stack/deque ./error_control
endif

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}

all: $(NAME)

bonus :
	make BONUS=1 all

$(NAME) : $(OBJS) $(LDLIBS)
	$(CC) $(OBJS) $(LDLIBS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -c

$(LDLIBS) : $(LDLIBS_DIR)
	make -C $< make

clean: $(LDLIBS_DIR)
	rm -f $(OBJS)
	make -C $< clean

fclean:	$(LDLIBS_DIR)
	make clean
	rm -rf ${NAME}
	make -C $< fclean

re: fclean all

.PHONY: all clean fclean re
