/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:47 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/02 11:39:33 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	drop_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->lock_right))
		return (0);
	if (pthread_mutex_unlock(philo->lock_left))
		return (0);
	return (1);
}

int	pick_up_forks(t_philo *philo)
{
	while (philo->id == *philo->left_fork || philo->id == *philo->right_fork)
		usleep(1);
	if (pthread_mutex_lock(philo->lock_left))
		return (1);
	*philo->left_fork = philo->id;
	printf("%ld %d has taken a [left] fork\n", get_timestamp_ms(), philo->id);
	if (pthread_mutex_lock(philo->lock_right))
		return (1);
	*philo->right_fork = philo->id;
	printf("%ld %d has taken a [right] fork\n", get_timestamp_ms(), philo->id);
	return (1);
}

int	eat(t_philo *philo)
{
	printf("%ld %d is eating\n", get_timestamp_ms(), philo->id);
	philo->last_meal_time = get_timestamp_ms();
	if (usleep(philo->info->eat_time * 1000) == -1)
		return (0);
	return (1);
}
