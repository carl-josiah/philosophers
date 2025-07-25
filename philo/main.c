/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:53 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/24 10:46:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy(t_philo *philo, t_info *info);

void	parsing_error(const char *str)
{
	printf(RED "ERROR: %s\n" WHT, str);
	printf("Usage: ./philo ");
	printf("[philo_count] [time_to_die] [time_to_eat] [time_to_sleep] ");
	printf(GRY "optional: [philo_required_meals]\n" WHT);
}

void	error_msg(const char *str)
{
	printf(RED "ERROR: %s\n" WHT, str);
}

static void	destroy(t_philo *philo, t_info *info)
{
	unsigned long long	i;

	i = 0;
	while (i < info->philo_count)
	{
		pthread_mutex_destroy(&philo[i].meal_count_lock);
		pthread_mutex_destroy(&philo[i].meal_time_lock);
		pthread_mutex_destroy(&info->fork_locks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print_lock);
	pthread_mutex_destroy(&info->death_lock);
	pthread_mutex_destroy(&info->meal_lock);
}

void	guard_state(pthread_mutex_t *mutex_lock, int lock_action)
{
	if (lock_action)
		pthread_mutex_lock(mutex_lock);
	else
		pthread_mutex_unlock(mutex_lock);
}

int	main(int ac, char **av)
{
	t_philo	philo[MAX_PHILO];
	t_info	info;

	if (!parsing(ac, av))
		return (EXIT_FAILURE);
	initialize(ac, av, philo, &info);
	if (!simulate(philo, &info))
		return (destroy(philo, &info), EXIT_FAILURE);
	destroy(philo, &info);
	return (EXIT_SUCCESS);
}
