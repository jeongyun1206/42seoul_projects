CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = $(SRCS:.c=.o)
SRCS = ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c  ft_memcpy.c  ft_memset.c  ft_strlcat.c ft_strlen.c  ft_strnstr.c ft_tolower.c ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c ft_memmove.c ft_strchr.c  ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

ifdef BONUS
	TOTAL_OBJS = $(OBJS) $(BONUS_OBJS)
	TOTAL_SRCS = $(SRCS) $(BONUS_SRCS)
else
	TOTAL_OBJS = $(OBJS)
	TOTAL_SRCS = $(SRCS)
endif

all : $(NAME)

$(NAME) : $(TOTAL_OBJS)
	ar -rc $@ $(TOTAL_OBJS)

$(TOTAL_OBJS) : $(TOTAL_SRCS)
	$(CC) $(CFLAGS) -c $^

bonus : 
	make BONUS=1 all

re : fclean all

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
fclean : clean
	rm -f $(NAME)

.PHONY: all clean fclean re bonus
