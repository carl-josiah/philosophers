/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:47 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/08 18:34:57 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	pick_up_forks(t_philo *philo)
{
	if (philo->info->philo_died)
		return (0);
	while (philo->id == *philo->left_fork || philo->id == *philo->right_fork)
	{
		if (philo->info->philo_died)
			return (0);
		usleep(1000);
	}
	if (philo->info->philo_died)
		return (0);
	pthread_mutex_lock(philo->lock_left);
	*philo->left_fork = philo->id;
	if (philo->info->philo_died)
	{
		pthread_mutex_unlock(philo->lock_left);
		return (0);
	}
	pthread_mutex_lock(philo->lock_right);
	*philo->right_fork = philo->id;
	return (1);
}

void	eat(t_philo *philo)
{
	if (philo->info->philo_died)
		return ;
	philo->last_meal_time = get_timestamp_ms();
	usleep(philo->info->eat_time * 1000);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->lock_right);
	pthread_mutex_unlock(philo->lock_left);
}
