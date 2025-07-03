/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:47 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/03 18:40:59 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	pick_up_forks(t_philo *philo)
{
	long	elapsed;

	while (philo->id == *philo->left_fork || philo->id == *philo->right_fork)
	{
		if (usleep(1000) == -1)
			return (0);
	}
	if (pthread_mutex_lock(philo->lock_left))
		return (0);
	*philo->left_fork = philo->id;
	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%ld %d has taken a [left] fork\n", elapsed, philo->id);
	*philo->right_fork = philo->id;
	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%ld %d has taken a [right] fork\n", elapsed, philo->id);
	return (1);
}

int	eat(t_philo *philo)
{
	long	elapsed;

	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%ld %d is eating\n", elapsed, philo->id);
	philo->last_meal_time = get_timestamp_ms();
	if (usleep(philo->info->eat_time * 1000) == -1)
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
