CPP = c++
CPPFALGS = -Wall -Werror -Wextra -std=c++98
SRCS = megaphone.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)
$(OBJS): $(SRCS)
	$(CPP) $(CPPFALGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus%