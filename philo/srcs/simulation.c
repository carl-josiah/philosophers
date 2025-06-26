/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:24:51 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 17:48:48 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	create_philo_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->philo_count)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]))
			return (0);
		i++;
	}
	return (1);
}

int	start_simulation(t_philo *philo, t_info *info)
{
	(void) info;
	if (!create_philo_threads(philo))
		return (0);
	return (1);
}
