NAME		= philo

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

THREAD		= -pthread

SRCS		= srcs/philo.c \
			srcs/utils1.c \
			srcs/parsing.c \
			srcs/utils2.c

OBJS		= $(SRCS:srcs/%.c=objs/%.o)

OBJS_DIR	= mkdir -p objs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREAD) $^ -o $@

objs/%.o: srcs/%.c
	$(OBJS_DIR)
	$(CC) $(CFLAGS) $(THREAD) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
