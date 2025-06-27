/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:24:51 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/27 05:37:09 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	create_philo_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->philo_count)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]))
			return (error_msg("pthread_create() FAILED"), 0);
		i++;
	}
	return (1);
}

int	start_simulation(t_philo *philo, t_info *info)
{
	pthread_t	monitor_thread;

	(void) info;
	if (!create_philo_threads(philo))
		return (0);
	if (pthread_create(&monitor_thread, NULL, monitoring_thread, (void *)info))
		return (error_msg("pthread_create() FAILED"), 0);
	return (1);
}
