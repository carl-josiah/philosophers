/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:40:16 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 16:51:56 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	philo_take_fork(t_sim *info)
{
	pthread_mutex_lock(info->philos->first_fork);
	print_philo_action(info->philos, TAKE_FORK, get_timestamp_ms());
	pthread_mutex_lock(info->philos->second_fork);
	print_philo_action(info->philos, TAKE_FORK, get_timestamp_ms());
}

void	philo_eating(t_sim *info)
{
	print_philo_action(info->philos, EATING, get_timestamp_ms());
	usleep(info->args->eat_time * 1000);
	pthread_mutex_unlock(info->philos->second_fork);
	pthread_mutex_unlock(info->philos->first_fork);
}

void	philo_sleeping(t_sim *info)
{
	print_philo_action(info->philos, SLEEPING, get_timestamp_ms());
	usleep(info->args->sleep_time * 1000);
}

void	philo_thinking(t_sim *info)
{
	print_philo_action(info->philos, THINKING, get_timestamp_ms());
}

void	philo_death(t_sim *info)
{
	print_philo_action(info->philos, DIED, get_timestamp_ms());
}
