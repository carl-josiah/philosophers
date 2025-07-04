/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:34:31 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/04 18:58:00 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	monitor_death(t_philo *philo);

static int	monitor_death(t_philo *philo)
{
	if ((get_timestamp_ms() - philo->last_meal_time) > philo->info->death_time)
	{
		if (!print_action(philo, DIED))
			return (0);
		return (1);
	}
	else
		return (0);
}

void	*monitor_routine(void *arg)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->info->philo_count)
		{
			if (monitor_death(&philo[i]))
				return (NULL);
			// if (monitor_meals(&philo[i]))
			// 	return (NULL);
			i++;
		}
		if (usleep(1000) == -1)
			return (NULL);
	}
	return (NULL);
}

int	monitor(t_philo *philo)
{
	pthread_t	monitor;

	(void) philo;
	if (pthread_create(&monitor, NULL, monitor_routine, philo))
		return (0);
	if (pthread_detach(monitor))
		return (0);
	return (1);
}
