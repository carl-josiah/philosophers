/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:47 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 11:37:30 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static void	which_to_pick(t_philo *philo);

static void	which_to_pick(t_philo *philo)
{
	if (philo->lock_left > philo->lock_right)
	{
		pthread_mutex_lock(philo->lock_right);
		*philo->right_fork = philo->id;
		printf("%d pickup right\n", philo->id);
		pthread_mutex_lock(philo->lock_left);
		*philo->left_fork = philo->id;
		printf("%d pickup left\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->lock_left);
		*philo->left_fork = philo->id;
		printf("%d pickup left\n", philo->id);
		pthread_mutex_lock(philo->lock_right);
		*philo->right_fork = philo->id;
		printf("%d pickup right\n", philo->id);
	}
}

void	pick_up_forks(t_philo *philo)
{
	while (philo->id == *philo->left_fork || philo->id == *philo->right_fork)
		usleep(1000);
	which_to_pick(philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal_time = get_timestamp_ms();
	printf("bro %d eating\n", philo->id);
	pthread_mutex_unlock(&philo->meal_time_lock);
	usleep(philo->info->eat_time * 1000);
}

void	drop_forks(t_philo *philo)
{
	if (philo->lock_left > philo->lock_right)
	{
		pthread_mutex_unlock(philo->lock_right);
		pthread_mutex_unlock(philo->lock_left);
	}
	else
	{
		pthread_mutex_unlock(philo->lock_left);
		pthread_mutex_unlock(philo->lock_right);
	}
}
