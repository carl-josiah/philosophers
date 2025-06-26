/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:49:11 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 17:42:30 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	philo_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_lock);
	printf("%ld %d is thinking\n", get_timestamp_ms(), philo->id);
	pthread_mutex_unlock(&philo->info->print_lock);
}

int	philo_eating(t_philo *philo)
{
	unsigned long long	meal_time;

	if (!philo_take_forks(philo))
		return (0);
	meal_time = get_timestamp_ms();
	pthread_mutex_lock(&philo->info->print_lock);
	printf("%lld %d is eating\n", meal_time, philo->id);
	pthread_mutex_unlock(&philo->info->print_lock);
	if (usleep(philo->info->eat_time) == -1)
		return (0);
	philo->last_meal_time = meal_time;
	philo->meal_count++;
	if (!philo_drop_forks(philo))
		return (0);
	return (1);
}

int	philo_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_lock);
	printf("%ld %d is sleeping\n", get_timestamp_ms(), philo->id);
	pthread_mutex_unlock(&philo->info->print_lock);
	if ((usleep(philo->info->sleep_time)) == -1)
		return (0);
	return (1);
}
