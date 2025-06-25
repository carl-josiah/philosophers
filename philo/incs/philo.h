/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:55 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/25 09:20:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define RED "\033[31m"
# define GREY "\033[90m"
# define DEFAULT "\033[0m"

# define DIED 0
# define THINKING 1
# define TAKE_FORK 2
# define EATING 3
# define SLEEPING 4
# define MAX_PHILO 200

typedef struct s_arg
{
	int	philo_count;
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	meal_limit;
}		t_arg;

typedef struct s_philo
{
	int				id;
	int				time;
	int				state;
	int				meal_count;
	pthread_t		thread;
	t_arg			*arg;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
}					t_philo;

typedef struct s_sim
{
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutexes;
	int					state;
	unsigned long long	start_time;
}						t_sim;

int		is_empty_arg(int ac, char **av);
int		is_all_digit(int ac, char **av);
int		is_valid_num(int ac, char **av);
int		is_over_max_philo(char **av);

int		is_valid_argc(int ac);
int		is_valid_argv(int ac, char **av);
int		is_correct_input(int ac, char **av);

int		philo_atoi_safe(char *str, int *out);

int		is_delim(char c);
int		is_sign(char c);
int		is_digit(char c);

void	error_message(const char *msg);

long	get_timestamp_ms(void);

#endif