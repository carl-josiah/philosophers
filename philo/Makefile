NAME = philo

FLAGS = -Wall -Wextra -Werror -pthread

SRCS = $(addsuffix .c,	main \
						utils \
						parse \
						init \
						sim \
						sim_utils \
						)

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ -o $@

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re