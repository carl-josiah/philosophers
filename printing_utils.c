/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:31:19 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/07 15:27:39 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	print_take_fork(t_philo *philo)
{
	long	elapsed;

	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%lu %d has taken a fork\n", elapsed, philo->id);
}

void	print_eating(t_philo *philo)
{
	long	elapsed;

	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%lu %d is eating\n", elapsed, philo->id);
}

void	print_thinking(t_philo *philo)
{
	long	elapsed;

	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%lu %d is thinking\n", elapsed, philo->id);
}

void	print_sleeping(t_philo *philo)
{
	long	elapsed;

	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%lu %d is sleeping\n", elapsed, philo->id);
}

void	print_died(t_philo *philo)
{
	long	elapsed;

	elapsed = get_timestamp_ms() - philo->info->start_time;
	printf("%lu %d died\n", elapsed, philo->id);
}
