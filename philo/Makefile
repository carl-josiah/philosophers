NAME		= philo

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g3

THREAD		= -pthread

SRCS		= srcs/philo.c \
			srcs/utils1.c \
			srcs/parsing1.c \
			srcs/parsing2.c \
			srcs/utils2.c \
			srcs/error.c \
			srcs/timing.c \
			srcs/init.c \
			srcs/init_philo_utils.c \
			srcs/init_info_utils.c \
			srcs/simulation.c \
			srcs/routine.c \
			srcs/routine_utils.c \
			srcs/simulation_utils.c \
			srcs/monitor.c \
			srcs/print.c \
			\
			srcs/test_init.c \

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