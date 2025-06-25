/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:55 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/25 13:03:47 by ccastro          ###   ########.fr       */
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

typedef struct s_philo
{
	int					id;
	int					meal_count;
	int					*left_fork;
	int					*right_fork;
	pthread_t			thread;
	struct s_info		*info;
	pthread_mutex_t		*left_lock;
	pthread_mutex_t		*right_lock;
	unsigned long long	last_meal_time;
}						t_philo;

typedef struct s_info
{
	int					philo_died;
	int					philo_count;
	int					required_meals;
	int					meals_finished;
	int					stop_simulation;
	int					forks[MAX_PHILO];
	pthread_t			philos[MAX_PHILO];
	struct s_philo		*philo_data;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		fork_locks[MAX_PHILO];
	unsigned long long	eat_time;
	unsigned long long	start_time;
	unsigned long long	death_time;
	unsigned long long	sleep_time;
}						t_info;

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