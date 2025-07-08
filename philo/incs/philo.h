/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:55 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/08 18:13:47 by ccastro          ###   ########.fr       */
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
# define TAKE_FORK 1
# define EATING 2
# define THINKING 3
# define SLEEPING 4
# define MAX_PHILO 200

typedef struct s_philo
{
	int					id;
	int					meal_count;
	unsigned long long	last_meal_time;
	int					*left_fork;
	int					*right_fork;
	pthread_mutex_t		*lock_left;
	pthread_mutex_t		*lock_right;
	pthread_t			thread;
	struct s_info		*info;
}						t_philo;

typedef struct s_info
{
	int					philo_count;
	unsigned long long	death_time;
	unsigned long long	eat_time;
	unsigned long long	sleep_time;
	int					required_meals;
	int					philo_died;
	int					meal_limit_reached;
	int					fork_init_flag;
	unsigned long long	start_time;
	int					forks[MAX_PHILO];
	pthread_mutex_t		fork_locks[MAX_PHILO];
	pthread_mutex_t		print_lock;
	struct s_philo		*philo;
}						t_info;

// parsing1.c
int		is_empty_arg(int ac, char **av);
int		is_all_digit(int ac, char **av);
int		is_valid_num(int ac, char **av);
int		is_over_max_philo(char **av);

// parsing2.c
int		is_valid_argc(int ac);
int		is_valid_argv(int ac, char **av);
int		is_correct_input(int ac, char **av);

// utils1.c
int		philo_atoi_safe(char *str, void *out);

// utils2.c
int		is_delim(char c);
int		is_sign(char c);
int		is_digit(char c);

// error.c
void	error_input(const char *msg);
void	error_msg(const char *msg);

// timing.c
long	get_timestamp_ms(void);

// init_info_utils.c
void	init_args(t_info *info, char **av);
void	init_forks(t_info *info);
int		init_fork_mutexes(t_info *info);

// init_philo_utils.c
void	init_id(t_philo *philo);
void	init_meal_count(t_philo *philo);
void	init_last_meal_time(t_philo *philo);
void	init_philo_forks(t_philo *philo);
void	init_philo_locks(t_philo *philo);

// init.c
int		init(t_philo *philo, t_info *info, char **av);

// simulation.c
int		start_simulation(t_philo *philo, t_info *info);

// simulation_utils.c
void	init_eating_order(t_info *info);
int		create_threads(t_philo *philo);
int		create_mutexes(t_info *info);
int		join_threads(t_philo *philo);
int		destroy_mutexes(t_info *info);

// routine.c
void	*routine(void *arg);

// routine_utils.c
void	drop_forks(t_philo *philo);
int		pick_up_forks(t_philo *philo);
void	eat(t_philo *philo);

// monitor.c
void	monitor(t_philo *philo, t_info *info);

#endif