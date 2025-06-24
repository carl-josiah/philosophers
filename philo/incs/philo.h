/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:55 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 09:25:47 by ccastro          ###   ########.fr       */
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

typedef struct s_info
{
	int	philo_count;
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	meal_limit;
}		t_info;

typedef struct s_philo
{
	int				id;
	int				time;
	int				state;
	int				meal_count;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
}					t_philo;

typedef struct s_sim
{
	t_info				*arg;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print_mutex;
	int					state;
	unsigned long long	start_time;
}						t_sim;

int		is_valid_argc(int ac);
int		is_valid_argv(int ac, char **av);

int		philo_atoi_safe(char *str, int *out);

int		is_delim(char c);
int		is_sign(char c);
int		is_digit(char c);

void	error_message(const char *msg);

void	init_data(int ac, char **av, t_info *data);
int		init_fork(t_sim *init);
int		allocate_memory(t_sim *init);

#endif