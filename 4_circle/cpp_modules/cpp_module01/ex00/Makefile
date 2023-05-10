CPP = c++
CPPFALGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = zombie

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)
*.o: %.c
	$(CPP) $(CPPFALGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus%