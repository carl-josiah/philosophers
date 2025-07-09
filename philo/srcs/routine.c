/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:15:20 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 11:32:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static void	philo_eating(t_philo *philo);
static void	philo_thinking(t_philo *philo);
static void	philo_sleeping(t_philo *philo);

static void	philo_eating(t_philo *philo)
{
	pick_up_forks(philo);
	eat(philo);
	drop_forks(philo);
}

static void	philo_thinking(t_philo *philo)
{
	printf("bro %d thinking\n", philo->id);
	usleep(1000);
}

static void	philo_sleeping(t_philo *philo)
{
	printf("bro %d sleeping\n", philo->id);
	usleep(philo->info->sleep_time * 1000);
}

static void	*single_philo_case(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_left);
	*philo->left_fork = philo->id;
	printf("bro %d pickup left\n", philo->id);
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
		philo_eating(philo);
		philo_thinking(philo);
		philo_sleeping(philo);
	}
	return (NULL);
}
