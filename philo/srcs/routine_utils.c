/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:47 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/03 16:18:53 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	philo_died_unlock_left(int philo_died, pthread_mutex_t *lock_left)
{
	if (philo_died)
	{
		if (pthread_mutex_unlock(lock_left))
			return (0);
		return (1);
	}
	return (0);
}

static int	philo_died_unlock_right(int philo_died, pthread_mutex_t *lock_right)
{
	if (philo_died)
	{
		if (pthread_mutex_unlock(lock_right))
			return (0);
		return (1);
	}
	return (0);
}

int	pick_up_forks(t_philo *philo)
{
	long	elapsed;

	if (philo->info->philo_died)
		return (0);
	while (philo->id == *philo->left_fork || philo->id == *philo->right_fork)
		if (usleep(1000) == -1)
			return (0);
	if (philo->info->philo_died)
		return (0);
	if (pthread_mutex_lock(philo->lock_left))
		return (0);
	if (philo_died_unlock_left(philo->info->philo_died, philo->lock_left))
		return (0);
	*philo->left_fork = philo->id;
	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%ld %d has taken a [left] fork\n", elapsed, philo->id);
	if (pthread_mutex_lock(philo->lock_right))
		return (0);
	if (philo_died_unlock_right(philo->info->philo_died, philo->lock_right))
		return (0);
	*philo->right_fork = philo->id;
	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%ld %d has taken a [right] fork\n", elapsed, philo->id);
	return (1);
}

int	eat(t_philo *philo)
{
	long	elapsed;

	if (philo->info->philo_died)
		return (0);
	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%ld %d is eating\n", elapsed, philo->id);
	philo->last_meal_time = get_timestamp_ms();
	if (usleep(philo->info->eat_time * 1000) == -1)
		return (0);
	if (philo->info->philo_died)
		return (0);
	return (1);
}

int	drop_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->lock_right))
		return (0);
	if (pthread_mutex_unlock(philo->lock_left))
		return (0);
	return (1);
}
