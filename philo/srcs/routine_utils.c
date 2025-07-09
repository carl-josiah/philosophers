/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:47 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 02:16:08 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// int	pick_up_forks(t_philo *philo)
// {
// 	if (is_simulation_end(philo->info))
// 		return (0);
// 	while (philo->id == *philo->left_fork || philo->id == *philo->right_fork)
// 	{
// 		if (is_simulation_end(philo->info))
// 		return (0);
// 		greater_usleep(1000, philo);
// 	}
// 	pthread_mutex_lock(philo->lock_left);
// 	if (is_simulation_end(philo->info))
// 		return (pthread_mutex_unlock(philo->lock_left), 0);
// 	*philo->left_fork = philo->id;
// 	pthread_mutex_lock(philo->lock_right);
// 	if (is_simulation_end(philo->info))
// 		return (pthread_mutex_unlock(philo->lock_right), 0);
// 	*philo->right_fork = philo->id;
// 	return (1);
// }

int	pick_up_forks(t_philo *philo)
{
    int first, second;

    if (is_simulation_end(philo->info))
        return (0);
    if (philo->left_fork < philo->right_fork)
    {
        first = 0;
        second = 1;
    }
    else
    {
        first = 1;
        second = 0;
    }
    pthread_mutex_t *forks[2] = {philo->lock_left, philo->lock_right};
    pthread_mutex_lock(forks[first]);
    if (is_simulation_end(philo->info))
        return (pthread_mutex_unlock(forks[first]), 0);
    pthread_mutex_lock(forks[second]);
    if (is_simulation_end(philo->info))
        return (pthread_mutex_unlock(forks[second]), pthread_mutex_unlock(forks[first]), 0);

    return (1);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal_time = get_timestamp_ms();
	printf("Philo %d starts eating at %llu (last_meal_time updated)\n",
        philo->id, philo->last_meal_time);
	pthread_mutex_unlock(&philo->meal_time_lock);
	greater_usleep(philo->info->eat_time, philo);
}

// void	drop_forks(t_philo *philo)
// {
// 	pthread_mutex_unlock(philo->lock_right);
// 	pthread_mutex_unlock(philo->lock_left);
// }

void	drop_forks(t_philo *philo)
{
    int first, second;

    if (philo->left_fork < philo->right_fork)
    {
        first = 0;
        second = 1;
    }
    else
    {
        first = 1;
        second = 0;
    }
    pthread_mutex_t *forks[2] = {philo->lock_left, philo->lock_right};
    pthread_mutex_unlock(forks[second]);
    pthread_mutex_unlock(forks[first]);
}
