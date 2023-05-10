CPP = c++
CPPFALGS = -Wall -Werror -Wextra -std=c++98
SRCS = contact.cpp phonebook.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = Phonebook

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFALGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus%