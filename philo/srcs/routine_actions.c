/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:49:11 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 13:54:55 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	philo_thinking(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_timestamp_ms(), philo->id);
}

int	philo_eating(t_philo *philo)
{
	unsigned long long	meal_time;

	meal_time = get_timestamp_ms();
	if (!philo_take_forks(philo))
		return (0);
	printf("%lld %d is eating\n", meal_time, philo->id);
	if (!usleep(philo->info->eat_time))
		return (0);
	philo->last_meal_time = meal_time;
	philo->meal_count++;
	if (!philo_drop_forks(philo))
		return (0);
	return (1);
}

int	philo_sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_timestamp_ms(), philo->id);
	if (!usleep(philo->info->sleep_time))
		return (0);
	return (1);
}
