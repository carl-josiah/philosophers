/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:31:40 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/25 11:49:56 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo);
static int	eating(t_philo *philo);

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (!even_take_forks(philo))
			return (0);
	}
	else
	{
		if (!odd_take_forks(philo))
			return (0);
	}
	usleep(100);
	return (1);
}

static int	eating(t_philo *philo)
{
	if (!print_action(philo, EATING))
		return (0);
	guard_state(&philo->meal_count_lock, LOCK);
	philo->meal_count++;
	guard_state(&philo->meal_count_lock, UNLOCK);
	guard_state(&philo->meal_time_lock, LOCK);
	philo->last_meal_time = curr_time();
	guard_state(&philo->meal_time_lock, UNLOCK);
	chunk_usleep(philo->info->time_to_eat, philo);
	return (1);
}

static void	single_philo_case(t_philo *philo)
{
	while (!is_dead(philo))
	{
		guard_state(philo->lock_right, LOCK);
		*philo->right_fork = philo->id;
		guard_state(philo->lock_right, UNLOCK);
		if (print_action(philo, TAKE_FORK))
			return ;
		chunk_usleep(philo->info->time_to_die, philo);
	}
}

void	*routine(void *arg)
{
	t_philo				*philo;

	philo = (t_philo *)arg;
	if (philo->info->philo_count == 1)
		single_philo_case(philo);
	while (!is_dead(philo) && !has_eaten_required_meals(philo))
	{
		if (!philo_has_eaten(philo))
		{
			if (!take_forks(philo))
				return (NULL);
			if (!eating(philo))
				return (NULL);
			if (!print_action(philo, THINKING))
				return (NULL);
			if (!print_action(philo, SLEEPING))
				return (0);
			chunk_usleep(philo->info->time_to_sleep, philo);
		}
		usleep(100);
	}
	return (NULL);
}

int	simulate(t_philo *philo, t_info *info)
{
	unsigned long long	i;

	philo->info->start_time = curr_time();
	init_philo_last_meal_time(philo, philo->info);
	init_fork_eating_order(philo, philo->info);
	i = 0;
	while (i < info->philo_count)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < info->philo_count)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}
