/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:49:24 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 01:25:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	is_simulation_end(t_info *info)
{
	int	died;

	pthread_mutex_lock(&info->status_lock);
	died = info->philo_died;
	pthread_mutex_unlock(&info->status_lock);
	return (died);
}

int	start_simulation(t_philo *philo, t_info *info)
{
	init_eating_order(info);
	create_mutexes(info);
	if (!create_threads(philo))
		return (0);
	info->start_time = get_timestamp_ms();
	init_last_meal_time(philo);
	monitor(philo, info);
	join_threads(philo);
	destroy_mutexes(info);
	return (1);
}
