CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ps_fill_stack.c push_swap.c \
		./error_control/error_control.c \
		./libft/ft_atoi.c \
		./ps_greedy/ps_greedy_move_element.c ./ps_greedy/ps_greedy_rotate_a_table.c ./ps_greedy/ps_greedy_sort_three_element.c \
		./ps_greedy/ps_greedy.c ./ps_greedy/ps_greedy_cmd_table.c ./ps_greedy/ps_greedy_partitioning.c \
		./ps_greedy/ps_greedy_sort_four_element.c ./ps_greedy/quick_sort.c \
		./ps_stack/deque/deque_ele_func.c  ./ps_stack/deque/deque_info_func.c ./ps_stack/deque/deque_init_func.c \
		./ps_stack/ps_stack_cmd_push.c ./ps_stack/ps_stack_cmd_rotate.c ./ps_stack/ps_stack_cmd_reverse_rotate.c \
		./ps_stack/ps_stack_cmd_swap.c ./ps_stack/ps_stack_init_func.c
OBJS = ${SRCS:.c=.o}
BONUS_SRCS = ps_fill_stack.c ./bonus_checker/checker.c\
		./bonus_checker/get_next_line/get_next_line.c ./bonus_checker/get_next_line/get_next_line_utils.c \
		./error_control/error_control.c \
		./libft/ft_atoi.c \
		./ps_stack/deque/deque_ele_func.c  ./ps_stack/deque/deque_info_func.c ./ps_stack/deque/deque_init_func.c \
		./ps_stack/ps_stack_cmd_push.c ./ps_stack/ps_stack_cmd_rotate.c ./ps_stack/ps_stack_cmd_reverse_rotate.c \
		./ps_stack/ps_stack_cmd_swap.c ./ps_stack/ps_stack_init_func.c \
		./ps_stack/checker_stack_cmd_push.c ./ps_stack/checker_stack_cmd_rotate.c ./ps_stack/checker_stack_cmd_reverse_rotate.c \
		./ps_stack/checker_stack_cmd_swap.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
BONUS_LDLIBS = ./bonus_checker/ft_printf/libftprintf.a
NAME = push_swap
BONUS_NAME = checker

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS) $(BONUS_LDLIBS)
	$(CC) $(BONUS_OBJS) $(BONUS_LDLIBS) -o $@

$(BONUS_LDLIBS) :
	make -C ./bonus_checker/ft_printf all

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C ./bonus_checker/ft_printf clean

fclean:	clean
	rm -rf ${NAME} $(BONUS_NAME)
	make -C ./bonus_checker/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
