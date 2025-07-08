/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:15:20 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/08 19:18:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	philo_eating(t_philo *philo);
static void	philo_thinking(t_philo *philo);
static void	philo_sleeping(t_philo *philo);

static int	philo_eating(t_philo *philo)
{
	if (philo->info->philo_died)
		return (0);
	if (!pick_up_forks(philo))
		return (0);
	eat(philo);
	drop_forks(philo);
	return (1);
}

static void	philo_thinking(t_philo *philo)
{
	(void) philo;
	usleep(1000);
}

static void	philo_sleeping(t_philo *philo)
{
	usleep(philo->info->sleep_time * 1000);
}

static void	*single_philo_case(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_left);
	*philo->left_fork = philo->id;
	usleep(philo->info->death_time * 1000);
	pthread_mutex_unlock(philo->lock_left);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->philo_count == 1)
		return (single_philo_case(philo));
	while (1)
	{
		if (philo->info->philo_died)
			return (NULL);
		if (!philo_eating(philo))
			return (NULL);
		philo_thinking(philo);
		philo_sleeping(philo);
	}
	return (NULL);
}
