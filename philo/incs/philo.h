/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:55 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/19 13:52:54 by ccastro          ###   ########.fr       */
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
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	req_meal_count;
}		t_info;

int		is_valid_argc(int ac);
int		is_valid_argv(int ac, char *av[]);

int		philo_atoi_safe(char *str, int *out);

int		is_delim(char c);
int		is_sign(char c);
int		is_digit(char c);

void	error_message(const char *msg);

#endif