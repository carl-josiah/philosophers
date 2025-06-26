/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:08:21 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 18:43:22 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	lock_order(t_philo *philo)
{
	if (philo->left_fork > philo->right_fork)
	{
		if (pthread_mutex_lock(philo->lock_right))
			return (error_msg("pthread_mutex_lock() FAILED"), 0);
		*philo->right_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
		if (pthread_mutex_lock(philo->lock_left))
			return (error_msg("pthread_mutex_lock() FAILED"), 0);
		*philo->left_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
	}
	else
	{
		if (pthread_mutex_lock(philo->lock_left))
			return (error_msg("pthread_mutex_lock() FAILED"), 0);
		*philo->left_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
		if (pthread_mutex_lock(philo->lock_right))
			return (error_msg("pthread_mutex_lock() FAILED"), 0);
		*philo->right_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
	}
	return (1);
}

static int	unlock_order(t_philo *philo)
{
	if (philo->left_fork > philo->right_fork)
	{
		*philo->left_fork = 0;
		if (pthread_mutex_unlock(philo->lock_left))
			return (error_msg("pthread_mutex_unlock() FAILED"), 0);
		*philo->right_fork = 0;
		if (pthread_mutex_unlock(philo->lock_right))
			return (error_msg("pthread_mutex_unlock() FAILED"), 0);
	}
	else
	{
		*philo->right_fork = 0;
		if (pthread_mutex_unlock(philo->lock_right))
			return (error_msg("pthread_mutex_unlock() FAILED"), 0);
		*philo->left_fork = 0;
		if (pthread_mutex_unlock(philo->lock_left))
			return (error_msg("pthread_mutex_unlock() FAILED"), 0);
	}
	return (1);
}

int	philo_take_forks(t_philo *philo)
{
	if (philo->info->philo_count == 1)
	{
		pthread_mutex_lock(philo->lock_left);
		*philo->left_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
		if (usleep(philo->info->death_time * 1000) == -1)
			return (error_msg("usleep() FAILED"), 0);
		pthread_mutex_lock(&philo->info->print_lock);
		philo->info->philo_died = 1;
		printf("%ld %d died\n", get_timestamp_ms(), philo->id);
		pthread_mutex_unlock(&philo->info->print_lock);
		return (0);
	}
	if (lock_order(philo))
		return (0);
	return (1);
}

int	philo_drop_forks(t_philo *philo)
{
	if (!unlock_order(philo))
		return (0);
	return (1);
}
