/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:47 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/04 18:07:37 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// static void	drop_one_fork(pthread_mutex_t *lock)
// {
// 	if (pthread_mutex_unlock(lock))
// 		error_msg("pthread_mutex_unlock() FAILED");
// }

int	pick_up_forks(t_philo *philo)
{
	while (philo->id == *philo->left_fork || philo->id == *philo->right_fork)
	{
		if (usleep(1000) == -1)
			return (0);
	}
	if (pthread_mutex_lock(philo->lock_left))
		return (0);
	*philo->left_fork = philo->id;
	if (!print_action(philo, TAKE_FORK))
		return (0);
	if (pthread_mutex_lock(philo->lock_right))
		return (0);
	*philo->right_fork = philo->id;
	if (!print_action(philo, TAKE_FORK))
		return (0);
	return (1);
}

int	eat(t_philo *philo)
{
	if (!print_action(philo, EATING))
		return (0);
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
