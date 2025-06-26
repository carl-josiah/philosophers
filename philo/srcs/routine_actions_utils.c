/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:08:21 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 17:35:54 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	is_turn(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->info->turn_lock);
		if (philo->info->turn != philo->id)
		{
			pthread_mutex_unlock(&philo->info->turn_lock);
			if (usleep(100) == -1)
				return (0);
		}
		else
		{
			pthread_mutex_unlock(&philo->info->turn_lock);
			break ;
		}
	}
	return (1);
}

static int	lock_order(t_philo *philo)
{
	if (philo->left_fork > philo->right_fork)
	{
		if (pthread_mutex_lock(philo->lock_right))
			return (0);
		*philo->right_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
		if (pthread_mutex_lock(philo->lock_left))
			return (0);
		*philo->left_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
	}
	else
	{
		if (pthread_mutex_lock(philo->lock_left))
			return (0);
		*philo->left_fork = philo->id;
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
		if (pthread_mutex_lock(philo->lock_right))
			return (0);
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
			return (0);
		*philo->right_fork = 0;
		if (pthread_mutex_unlock(philo->lock_right))
			return (0);
	}
	else
	{
		*philo->right_fork = 0;
		if (pthread_mutex_unlock(philo->lock_right))
			return (0);
		*philo->left_fork = 0;
		if (pthread_mutex_unlock(philo->lock_left))
			return (0);
	}
	return (1);
}

int	philo_take_forks(t_philo *philo)
{
	if (is_turn(philo))
	{
		if (lock_order(philo))
			return (0);
	}
	return (1);
}

int	philo_drop_forks(t_philo *philo)
{
	if (!unlock_order(philo))
		return (0);
	return (1);
}
