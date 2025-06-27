/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:24:51 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/27 16:01:11 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	create_philo_threads(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]))
			return (error_msg("pthread_create() FAILED"), 0);
		i++;
	}
	return (1);
}

static int	wait_for_philos(t_philo *philo)
{
	int	i;
	int	philos;
	
	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (error_msg("pthread_join() FAILED"), 0);
		i++;
	}
	return (1);
}

int	start_simulation(t_philo *philo, t_info *info)
{
	// pthread_t	monitor_thread;

	(void) info;
	if (!create_philo_threads(philo))
		return (0);
	// if (pthread_create(&monitor_thread, NULL, monitoring_thread, (void *)info))
	// 	return (error_msg("pthread_create() FAILED"), 0);
	if (!wait_for_philos(philo))
		return (0);
	// if (pthread_join(monitor_thread, NULL))
	// 	return (error_msg("pthread_join() FAILED"), 0);
	return (1);
}
