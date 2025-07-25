/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:07:11 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/25 15:43:57 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define RED "\e[0;31m"
# define GRY "\e[0;90m"
# define WHT "\e[0;37m"

# define ERR_AC "MUST BE (5) OR (6) ARGUMENTS"
# define ERR_AV_NUM "MUST ONLY BE (POSITIVE NUMBERS)"
# define ERR_AV_ZERO "MUST BE GREATER THAN (0)"
# define ERR_INT_MAX "MUST BE LESS THAN (INT MAX)"
# define ERR_PHILO_COUNT "[philo_count] MUST BE LESS THAN OR EQUAL TO (200)"
# define ZERO 0
# define GREATER_MAX -1
# define LOCK 1
# define UNLOCK 0

# define MAX_PHILO 200
# define DIED 0
# define TAKE_FORK 1
# define EATING 2
# define THINKING 3
# define SLEEPING 4

typedef struct s_philo
{
	int					id;
	int					meal_count;
	unsigned long long	last_meal_time;
	int					*left_fork;
	int					*right_fork;
	pthread_mutex_t		*lock_left;
	pthread_mutex_t		*lock_right;
	pthread_mutex_t		meal_count_lock;
	pthread_mutex_t		meal_time_lock;
	pthread_t			thread;
	struct s_info		*info;
}						t_philo;

typedef struct s_info
{
	unsigned long long	philo_count;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	required_meals;
	int					death_flag;
	int					init_fork_flag;
	unsigned long long	start_time;
	int					forks[MAX_PHILO];
	pthread_mutex_t		fork_locks[MAX_PHILO];
	pthread_mutex_t		print_lock;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		meal_lock;
	struct s_philo		*philo;
}						t_info;

// main.c
void				parsing_error(const char *str);
void				error_msg(const char *str);
void				guard_state(pthread_mutex_t *mutex_lock, int lock_action);

// utils.c
int					ft_atol(const char *str, unsigned long long *num);
unsigned long long	curr_time(void);
void				chunk_usleep(unsigned long long ms, t_philo *philo);
void				single_philo_case(t_philo *philo);
int					print_action(t_philo *philo, int action);

// parse.c
int					parsing(int ac, char **av);

// init.c
void				init_philo_last_meal_time(t_philo *philo, t_info *info);
void				init_fork_eating_order(t_philo *philo, t_info *info);
void				initialize(int ac, char **av, t_philo *philo, t_info *info);

// sim.c
int					is_dead(t_philo *philo);
int					simulate(t_philo *philo, t_info *info);

// sim_utils.c
int					is_dead(t_philo *philo);
int					has_eaten_required_meals(t_philo *philo);
int					philo_has_eaten(t_philo *philo);
int					odd_take_forks(t_philo *philo);
int					even_take_forks(t_philo *philo);

#endif
